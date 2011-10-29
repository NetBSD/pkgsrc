$NetBSD: patch-tools_libxl_libxl_create.c,v 1.1 2011/10/29 10:20:52 jmcneill Exp $

--- tools/libxl/libxl_create.c.orig	2011-10-20 17:05:42.000000000 +0000
+++ tools/libxl/libxl_create.c
@@ -171,7 +171,7 @@ int libxl__domain_build(libxl_ctx *ctx, 
         vments[2] = "image/ostype";
         vments[3] = "hvm";
         vments[4] = "start_time";
-        vments[5] = libxl__sprintf(&gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[5] = libxl__sprintf(&gc, "%llu.%02d", (unsigned long long)start_time.tv_sec,(int)start_time.tv_usec/10000);
     } else {
         ret = libxl__build_pv(ctx, domid, info, state);
         if (ret)
@@ -184,7 +184,7 @@ int libxl__domain_build(libxl_ctx *ctx, 
         vments[i++] = "image/kernel";
         vments[i++] = (char*) info->kernel.path;
         vments[i++] = "start_time";
-        vments[i++] = libxl__sprintf(&gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[i++] = libxl__sprintf(&gc, "%llu.%02d", (unsigned long long)start_time.tv_sec,(int)start_time.tv_usec/10000);
         if (info->u.pv.ramdisk.path) {
             vments[i++] = "image/ramdisk";
             vments[i++] = (char*) info->u.pv.ramdisk.path;
@@ -227,7 +227,7 @@ static int domain_restore(libxl_ctx *ctx
         vments[2] = "image/ostype";
         vments[3] = "hvm";
         vments[4] = "start_time";
-        vments[5] = libxl__sprintf(&gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[5] = libxl__sprintf(&gc, "%llu.%02d", (unsigned long long)start_time.tv_sec,(int)start_time.tv_usec/10000);
     } else {
         vments = libxl__calloc(&gc, 11, sizeof(char *));
         i = 0;
@@ -236,7 +236,7 @@ static int domain_restore(libxl_ctx *ctx
         vments[i++] = "image/kernel";
         vments[i++] = (char*) info->kernel.path;
         vments[i++] = "start_time";
-        vments[i++] = libxl__sprintf(&gc, "%lu.%02d", start_time.tv_sec,(int)start_time.tv_usec/10000);
+        vments[i++] = libxl__sprintf(&gc, "%llu.%02d", (unsigned long long)start_time.tv_sec,(int)start_time.tv_usec/10000);
         if (info->u.pv.ramdisk.path) {
             vments[i++] = "image/ramdisk";
             vments[i++] = (char*) info->u.pv.ramdisk.path;
