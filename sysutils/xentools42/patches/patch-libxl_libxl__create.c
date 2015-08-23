$NetBSD: patch-libxl_libxl__create.c,v 1.2 2015/08/23 16:17:12 spz Exp $

--- libxl/libxl_create.c.orig	2014-09-02 06:22:57.000000000 +0000
+++ libxl/libxl_create.c
@@ -355,7 +355,7 @@ int libxl__domain_build(libxl__gc *gc,
         vments[2] = "image/ostype";
         vments[3] = "hvm";
         vments[4] = "start_time";
-        vments[5] = libxl__sprintf(gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[5] = libxl__sprintf(gc, "%jd.%02d", (intmax_t)start_time.tv_sec, (int)start_time.tv_usec/10000);
 
         localents = libxl__calloc(gc, 7, sizeof(char *));
         localents[0] = "platform/acpi";
@@ -378,7 +378,7 @@ int libxl__domain_build(libxl__gc *gc,
         vments[i++] = "image/kernel";
         vments[i++] = (char *) state->pv_kernel.path;
         vments[i++] = "start_time";
-        vments[i++] = libxl__sprintf(gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[i++] = libxl__sprintf(gc, "%jd.%02d", (intmax_t)start_time.tv_sec, (int)start_time.tv_usec/10000);
         if (state->pv_ramdisk.path) {
             vments[i++] = "image/ramdisk";
             vments[i++] = (char *) state->pv_ramdisk.path;
@@ -849,7 +849,7 @@ void libxl__xc_domain_restore_done(libxl
         vments[2] = "image/ostype";
         vments[3] = "hvm";
         vments[4] = "start_time";
-        vments[5] = libxl__sprintf(gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[5] = libxl__sprintf(gc, "%jd.%02d", (intmax_t)start_time.tv_sec, (int)start_time.tv_usec/10000);
         break;
     case LIBXL_DOMAIN_TYPE_PV:
         vments = libxl__calloc(gc, 11, sizeof(char *));
@@ -859,7 +859,7 @@ void libxl__xc_domain_restore_done(libxl
         vments[i++] = "image/kernel";
         vments[i++] = (char *) state->pv_kernel.path;
         vments[i++] = "start_time";
-        vments[i++] = libxl__sprintf(gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[i++] = libxl__sprintf(gc, "%jd.%02d", (intmax_t)start_time.tv_sec, (int)start_time.tv_usec/10000);
         if (state->pv_ramdisk.path) {
             vments[i++] = "image/ramdisk";
             vments[i++] = (char *) state->pv_ramdisk.path;
