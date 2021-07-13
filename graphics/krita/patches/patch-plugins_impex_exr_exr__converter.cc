$NetBSD: patch-plugins_impex_exr_exr__converter.cc,v 1.1 2021/07/13 11:28:28 markd Exp $

openexr3 fix

--- plugins/impex/exr/exr_converter.cc.orig	2021-03-22 10:06:59.000000000 +0000
+++ plugins/impex/exr/exr_converter.cc
@@ -24,6 +24,8 @@
 
 #include <ImfAttribute.h>
 #include <ImfChannelList.h>
+#include <ImfFrameBuffer.h>
+#include <ImfHeader.h>
 #include <ImfInputFile.h>
 #include <ImfOutputFile.h>
 
