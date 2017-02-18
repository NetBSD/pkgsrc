$NetBSD: patch-src_external_rawspeed_RawSpeed_ColorFilterArray.cpp,v 1.1 2017/02/18 23:17:02 joerg Exp $

--- src/external/rawspeed/RawSpeed/ColorFilterArray.cpp.orig	2017-02-18 19:34:05.552264374 +0000
+++ src/external/rawspeed/RawSpeed/ColorFilterArray.cpp
@@ -85,13 +85,14 @@ CFAColor ColorFilterArray::getColorAt( u
   return cfa[x+y*size.x];
 }
 
-void ColorFilterArray::setCFA( iPoint2D in_size, ... )
+void ColorFilterArray::setCFA(int sizeA, int sizeB, ... )
 {
+  iPoint2D in_size(sizeA, sizeB);
   if (in_size != size) {
     setSize(in_size);
   }
   va_list arguments;
-  va_start(arguments, in_size);
+  va_start(arguments, sizeB);
   for (uint32 i = 0; i <  size.area(); i++ ) {
     cfa[i] = (CFAColor)va_arg(arguments, int);
   }
