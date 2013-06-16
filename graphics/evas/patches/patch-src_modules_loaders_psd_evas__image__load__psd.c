$NetBSD: patch-src_modules_loaders_psd_evas__image__load__psd.c,v 1.3 2013/06/16 18:56:05 sno Exp $

jperkin knows o.O (but didn't use pkglint)

--- src/modules/loaders/psd/evas_image_load_psd.c.orig	2011-08-11 07:46:01.000000000 +0200
+++ src/modules/loaders/psd/evas_image_load_psd.c	2011-12-27 15:15:11.097276116 +0100
@@ -1,4 +1,6 @@
+#ifndef _XOPEN_SOURCE
 #define _XOPEN_SOURCE
+#endif
 
 #ifdef HAVE_CONFIG_H
 # include <config.h>
