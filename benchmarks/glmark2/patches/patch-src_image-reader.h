$NetBSD: patch-src_image-reader.h,v 1.1 2015/03/08 23:25:39 joerg Exp $

--- src/image-reader.h.orig	2015-03-05 10:43:06.000000000 +0000
+++ src/image-reader.h
@@ -32,7 +32,7 @@ public:
     virtual ~ImageReader() {}
 };
 
-class PNGReaderPrivate;
+struct PNGReaderPrivate;
 
 class PNGReader : public ImageReader
 {
@@ -54,7 +54,7 @@ private:
     PNGReaderPrivate *priv_;
 };
 
-class JPEGReaderPrivate;
+struct JPEGReaderPrivate;
 
 class JPEGReader : public ImageReader
 {
