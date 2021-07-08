$NetBSD: patch-src_imageformats_exr.cpp,v 1.1 2021/07/08 21:31:49 markd Exp $

use openexr 3.x

--- src/imageformats/exr.cpp.orig	2021-03-04 21:57:23.000000000 +0000
+++ src/imageformats/exr.cpp
@@ -13,6 +13,7 @@
 #include <ImfStandardAttributes.h>
 #include <ImathBox.h>
 #include <ImfInputFile.h>
+#include <ImfInt64.h>
 #include <ImfBoxAttribute.h>
 #include <ImfChannelListAttribute.h>
 #include <ImfCompressionAttribute.h>
