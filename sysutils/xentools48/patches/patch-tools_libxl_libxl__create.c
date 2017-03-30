$NetBSD: patch-tools_libxl_libxl__create.c,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/libxl/libxl_create.c.orig	2016-12-05 13:03:27.000000000 +0100
+++ tools/libxl/libxl_create.c	2017-03-24 18:03:19.000000000 +0100
@@ -451,7 +451,7 @@
         vments[2] = "image/ostype";
         vments[3] = "hvm";
         vments[4] = "start_time";
-        vments[5] = GCSPRINTF("%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[5] = GCSPRINTF("%jd.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
 
         localents = libxl__calloc(gc, 9, sizeof(char *));
         i = 0;
@@ -488,7 +488,7 @@
         vments[i++] = "image/kernel";
         vments[i++] = (char *) state->pv_kernel.path;
         vments[i++] = "start_time";
-        vments[i++] = GCSPRINTF("%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[i++] = GCSPRINTF("%jd.%02d", (intmax_t)start_time.tv_sec,(int)start_time.tv_usec/10000);
         if (state->pv_ramdisk.path) {
             vments[i++] = "image/ramdisk";
             vments[i++] = (char *) state->pv_ramdisk.path;
@@ -1161,7 +1161,7 @@
         vments[2] = "image/ostype";
         vments[3] = "hvm";
         vments[4] = "start_time";
-        vments[5] = GCSPRINTF("%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[5] = GCSPRINTF("%jd.%02d", (intmax_t)start_time.tv_sec,(int)start_time.tv_usec/10000);
         break;
     case LIBXL_DOMAIN_TYPE_PV:
         vments = libxl__calloc(gc, 11, sizeof(char *));
@@ -1171,7 +1171,7 @@
         vments[i++] = "image/kernel";
         vments[i++] = (char *) state->pv_kernel.path;
         vments[i++] = "start_time";
-        vments[i++] = GCSPRINTF("%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[i++] = GCSPRINTF("%jd.%02d", (intmax_t)start_time.tv_sec,(int)start_time.tv_usec/10000);
         if (state->pv_ramdisk.path) {
             vments[i++] = "image/ramdisk";
             vments[i++] = (char *) state->pv_ramdisk.path;
