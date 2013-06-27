$NetBSD: patch-src_jpeg.c,v 1.1 2013/06/27 15:49:43 joerg Exp $

--- src/jpeg.c.orig	2013-06-26 22:52:18.000000000 +0000
+++ src/jpeg.c
@@ -21,6 +21,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #ifdef HAVE_JPEGLIB_H
 #include <jpeglib.h>
