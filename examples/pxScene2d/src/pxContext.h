#ifndef PX_CONTEXT_H
#define PX_CONTEXT_H

#include "pxCore.h"
#include "pxOffscreen.h"
#include "pxMatrix4T.h"
#include "rtCore.h"
#include "rtRefT.h"
#include "pxTexture.h"

enum pxStretch { PX_NONE = 0, PX_STRETCH = 1, PX_REPEAT = 2 };

class pxContext {
 public:

  pxContext(): mShowOutlines(false) {}

  void init();
  
  // debugging outlines 
  bool showOutlines() { return mShowOutlines; }
  void setShowOutlines(bool v) { mShowOutlines = v; }

  void setSize(int w, int h);
  void clear(int w, int h);
  void clear(int left, int top, int width, int height);

  void setMatrix(pxMatrix4f& m);
  pxMatrix4f getMatrix();
  void setAlpha(float a);
  void mapToScreenCoordinates(float inX, float inY, int &outX, int &outY);
 void mapToScreenCoordinates(pxMatrix4f& m, float inX, float inY, int &outX, int &outY);
  
  pxTextureRef createContextSurface(int width, int height);
  pxError updateContextSurface(pxTextureRef texture, int width, int height);
  pxError setRenderSurface(pxTextureRef texture);
  pxTextureRef getCurrentRenderSurface();
  pxError deleteContextSurface(pxTextureRef texture);

  pxTextureRef createTexture(pxOffscreen& o);
  pxTextureRef createTexture(float w, float h, float iw, float ih, void* buffer);

  void drawRect(float w, float h, float lineWidth, float* fillColor, float* lineColor);

  void drawImage(float x, float y, float w, float h, pxTextureRef t, pxTextureRef mask,
                 pxStretch xStretch, pxStretch yStretch, float* color = NULL);

  void drawImage9(float w, float h, float x1, float y1,
                  float x2, float y2, pxTextureRef texture);

// Only use for debug/diag purposes not for normal rendering
  void drawDiagRect(float x, float y, float w, float h, float* color);
  void drawDiagLine(float x1, float y1, float x2, float y2, float* color);

private:
  bool mShowOutlines;

};


#endif
