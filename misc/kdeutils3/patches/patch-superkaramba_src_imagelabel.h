$NetBSD: patch-superkaramba_src_imagelabel.h,v 1.1 2013/03/26 23:30:46 joerg Exp $

--- superkaramba/src/imagelabel.h.orig	2013-03-26 21:30:40.000000000 +0000
+++ superkaramba/src/imagelabel.h
@@ -38,7 +38,9 @@
 #include "karamba.h"
 
 class ImageLabel;
-class KIO::CopyJob;
+namespace KIO {
+  class CopyJob;
+}
 
 // Abstract Effects Baseclass
 class Effect : public QObject
