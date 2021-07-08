$NetBSD: patch-modules_imgcodecs_src_grfmt__exr.cpp,v 1.1 2021/07/08 21:27:39 markd Exp $

openexr3

--- modules/imgcodecs/src/grfmt_exr.cpp.orig	2019-12-19 15:16:47.000000000 +0000
+++ modules/imgcodecs/src/grfmt_exr.cpp
@@ -56,6 +56,7 @@
 #include <iostream>
 #include <stdexcept>
 
+#include <ImfFrameBuffer.h>
 #include <ImfHeader.h>
 #include <ImfInputFile.h>
 #include <ImfOutputFile.h>
