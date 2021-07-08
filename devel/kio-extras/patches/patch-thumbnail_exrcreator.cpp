$NetBSD: patch-thumbnail_exrcreator.cpp,v 1.1 2021/07/08 21:28:32 markd Exp $

openexr3

--- thumbnail/exrcreator.cpp.orig	2021-02-24 23:05:55.000000000 +0000
+++ thumbnail/exrcreator.cpp
@@ -23,6 +23,7 @@
 #include <QImage>
 #include <QFile>
 
+#include <ImfHeader.h>
 #include <ImfInputFile.h>
 #include <ImfPreviewImage.h>
 
