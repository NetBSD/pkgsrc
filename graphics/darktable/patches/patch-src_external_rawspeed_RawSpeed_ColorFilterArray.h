$NetBSD: patch-src_external_rawspeed_RawSpeed_ColorFilterArray.h,v 1.1 2017/02/18 23:17:02 joerg Exp $

Only POD types can be used with variadic functions.

--- src/external/rawspeed/RawSpeed/ColorFilterArray.h.orig	2017-02-18 19:39:46.465232404 +0000
+++ src/external/rawspeed/RawSpeed/ColorFilterArray.h
@@ -52,7 +52,7 @@ public:
   virtual ~ColorFilterArray(void);
   virtual void setSize(iPoint2D size);
   void setColorAt(iPoint2D pos, CFAColor c);
-  virtual void setCFA(iPoint2D size, ...);
+  virtual void setCFA(int sizeA, int sizeB, ...);
   CFAColor* getCfaWrt() {return cfa;};
   virtual CFAColor getColorAt(uint32 x, uint32 y);
   virtual uint32 getDcrawFilter();
