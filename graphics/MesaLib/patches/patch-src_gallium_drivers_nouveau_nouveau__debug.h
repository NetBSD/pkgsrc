$NetBSD: patch-src_gallium_drivers_nouveau_nouveau__debug.h,v 1.1 2018/01/16 15:49:47 jperkin Exp $

Avoid "C++11 requires a space between literal and identifier" error.

--- src/gallium/drivers/nouveau/nouveau_debug.h.orig	2016-05-09 12:20:52.000000000 +0000
+++ src/gallium/drivers/nouveau/nouveau_debug.h
@@ -16,7 +16,7 @@
 #define NOUVEAU_DEBUG 0
 
 #define NOUVEAU_ERR(fmt, args...)                                 \
-   fprintf(stderr, "%s:%d - "fmt, __FUNCTION__, __LINE__, ##args)
+   fprintf(stderr, "%s:%d - " fmt, __FUNCTION__, __LINE__, ##args)
 
 #define NOUVEAU_DBG(ch, args...)           \
    if ((NOUVEAU_DEBUG) & (NOUVEAU_DEBUG_##ch))        \
