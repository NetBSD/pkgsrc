$NetBSD: patch-libxl_libxl__create.c,v 1.1 2013/05/15 06:58:50 jnemeth Exp $

--- libxl/libxl_create.c.orig	2012-12-17 15:01:09.000000000 +0000
+++ libxl/libxl_create.c
@@ -338,7 +338,7 @@ int libxl__domain_build(libxl__gc *gc,
         vments[2] = "image/ostype";
         vments[3] = "hvm";
         vments[4] = "start_time";
-        vments[5] = libxl__sprintf(gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[5] = libxl__sprintf(gc, "%jd.%02d", (intmax_t)start_time.tv_sec, (int)start_time.tv_usec/10000);
 
         localents = libxl__calloc(gc, 7, sizeof(char *));
         localents[0] = "platform/acpi";
@@ -361,7 +361,7 @@ int libxl__domain_build(libxl__gc *gc,
         vments[i++] = "image/kernel";
         vments[i++] = (char *) state->pv_kernel.path;
         vments[i++] = "start_time";
-        vments[i++] = libxl__sprintf(gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[i++] = libxl__sprintf(gc, "%jd.%02d", (intmax_t)start_time.tv_sec, (int)start_time.tv_usec/10000);
         if (state->pv_ramdisk.path) {
             vments[i++] = "image/ramdisk";
             vments[i++] = (char *) state->pv_ramdisk.path;
@@ -832,7 +832,7 @@ void libxl__xc_domain_restore_done(libxl
         vments[2] = "image/ostype";
         vments[3] = "hvm";
         vments[4] = "start_time";
-        vments[5] = libxl__sprintf(gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[5] = libxl__sprintf(gc, "%jd.%02d", (intmax_t)start_time.tv_sec, (int)start_time.tv_usec/10000);
         break;
     case LIBXL_DOMAIN_TYPE_PV:
         vments = libxl__calloc(gc, 11, sizeof(char *));
@@ -842,7 +842,7 @@ void libxl__xc_domain_restore_done(libxl
         vments[i++] = "image/kernel";
         vments[i++] = (char *) state->pv_kernel.path;
         vments[i++] = "start_time";
-        vments[i++] = libxl__sprintf(gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[i++] = libxl__sprintf(gc, "%jd.%02d", (intmax_t)start_time.tv_sec, (int)start_time.tv_usec/10000);
         if (state->pv_ramdisk.path) {
             vments[i++] = "image/ramdisk";
             vments[i++] = (char *) state->pv_ramdisk.path;
