$NetBSD: patch-src_bin_loaders_psd_evas__image__load__psd.c,v 1.1 2016/02/14 13:14:06 jperkin Exp $

Don't redefine _XOPEN_SOURCE on SunOS.

--- src/bin/loaders/psd/evas_image_load_psd.c.orig	2012-11-23 16:35:06.000000000 +0000
+++ src/bin/loaders/psd/evas_image_load_psd.c
@@ -1,4 +1,6 @@
+#ifndef __sun
 #define _XOPEN_SOURCE
+#endif
 
 #ifdef HAVE_CONFIG_H
 # include <config.h>
