$NetBSD: patch-libxl_libxl__create.c,v 1.1 2015/01/20 16:42:13 bouyer Exp $

--- libxl/libxl_create.c.orig	2015-01-12 17:53:24.000000000 +0100
+++ libxl/libxl_create.c	2015-01-19 14:08:19.000000000 +0100
@@ -432,7 +432,7 @@
         vments[2] = "image/ostype";
         vments[3] = "hvm";
         vments[4] = "start_time";
-        vments[5] = libxl__sprintf(gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[5] = libxl__sprintf(gc, "%jd.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
 
         localents = libxl__calloc(gc, 9, sizeof(char *));
         i = 0;
@@ -469,7 +469,7 @@
         vments[i++] = "image/kernel";
         vments[i++] = (char *) state->pv_kernel.path;
         vments[i++] = "start_time";
-        vments[i++] = libxl__sprintf(gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[i++] = libxl__sprintf(gc, "%jd.%02d", (intmax_t)start_time.tv_sec, (int)start_time.tv_usec/10000);
         if (state->pv_ramdisk.path) {
             vments[i++] = "image/ramdisk";
             vments[i++] = (char *) state->pv_ramdisk.path;
@@ -1061,7 +1061,7 @@
         vments[2] = "image/ostype";
         vments[3] = "hvm";
         vments[4] = "start_time";
-        vments[5] = libxl__sprintf(gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[5] = libxl__sprintf(gc, "%jd.%02d", (intmax_t)start_time.tv_sec, (int)start_time.tv_usec/10000);
         break;
     case LIBXL_DOMAIN_TYPE_PV:
         vments = libxl__calloc(gc, 11, sizeof(char *));
@@ -1071,7 +1071,7 @@
         vments[i++] = "image/kernel";
         vments[i++] = (char *) state->pv_kernel.path;
         vments[i++] = "start_time";
-        vments[i++] = libxl__sprintf(gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[i++] = libxl__sprintf(gc, "%jd.%02d", (intmax_t)start_time.tv_sec, (int)start_time.tv_usec/10000);
         if (state->pv_ramdisk.path) {
             vments[i++] = "image/ramdisk";
             vments[i++] = (char *) state->pv_ramdisk.path;
