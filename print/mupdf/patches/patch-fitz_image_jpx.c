$NetBSD: patch-fitz_image_jpx.c,v 1.1 2012/12/08 23:09:40 adam Exp $

Fix path to openjpeg include.

--- fitz/image_jpx.c.orig	2012-12-08 22:53:28.000000000 +0000
+++ fitz/image_jpx.c
@@ -1,7 +1,7 @@
 #include "fitz-internal.h"
 
 #define OPJ_STATIC
-#include <openjpeg.h>
+#include <openjpeg-1.5/openjpeg.h>
 
 static void fz_opj_error_callback(const char *msg, void *client_data)
 {
