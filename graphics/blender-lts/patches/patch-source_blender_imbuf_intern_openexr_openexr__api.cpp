$NetBSD: patch-source_blender_imbuf_intern_openexr_openexr__api.cpp,v 1.1 2021/07/13 13:05:08 markd Exp $

openexr3 patch

--- source/blender/imbuf/intern/openexr/openexr_api.cpp.orig	2020-08-31 12:03:18.000000000 +0000
+++ source/blender/imbuf/intern/openexr/openexr_api.cpp
@@ -38,8 +38,10 @@
 #include <ImfChannelList.h>
 #include <ImfCompression.h>
 #include <ImfCompressionAttribute.h>
+#include <ImfFrameBuffer.h>
 #include <ImfIO.h>
 #include <ImfInputFile.h>
+#include <ImfInt64.h>
 #include <ImfOutputFile.h>
 #include <ImfPixelType.h>
 #include <ImfStandardAttributes.h>
