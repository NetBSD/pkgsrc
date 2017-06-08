$NetBSD: patch-cups_colord.h,v 1.1 2017/06/08 01:28:10 khorben Exp $

Fix build with cups 2.2.0

--- cups/colord.h.orig	2012-08-08 08:01:36.000000000 +0000
+++ cups/colord.h
@@ -27,6 +27,7 @@ MIT Open Source License  -  http://www.o
 
 /* Common routines for accessing the colord CMS framework */
 
+#include <cups/ppd.h>
 #include <cups/raster.h>
 
 char  **colord_get_qualifier_for_ppd      (ppd_file_t *ppd);
