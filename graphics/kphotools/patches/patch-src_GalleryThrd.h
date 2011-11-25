$NetBSD: patch-src_GalleryThrd.h,v 1.1 2011/11/25 21:58:42 joerg Exp $

--- src/GalleryThrd.h.orig	2011-11-25 19:15:55.000000000 +0000
+++ src/GalleryThrd.h
@@ -34,9 +34,11 @@
 
 //needed datatypes
 #include "FileItem.h"
-#include <vector.h>
+#include <vector>
 #include <qfile.h>
 
+using std::vector;
+
 //class definition
  class GalleryThrd  : public QThread{
  	//private member vars
