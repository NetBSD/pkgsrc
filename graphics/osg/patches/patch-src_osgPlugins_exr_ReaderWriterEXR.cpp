$NetBSD: patch-src_osgPlugins_exr_ReaderWriterEXR.cpp,v 1.1 2021/07/09 10:30:11 markd Exp $

openexr3 fix

--- src/osgPlugins/exr/ReaderWriterEXR.cpp.orig	2020-01-31 11:03:07.000000000 +0000
+++ src/osgPlugins/exr/ReaderWriterEXR.cpp
@@ -13,6 +13,7 @@
 #include <osgDB/FileNameUtils>
 #include <osgDB/FileUtils>
 
+#include <ImfInt64.h>
 #include <ImfRgbaFile.h>
 #include <ImfIO.h>
 #include <ImfArray.h>
