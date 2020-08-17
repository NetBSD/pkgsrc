$NetBSD: patch-src_modules_loaders_loader__argb.c,v 1.1 2020/08/17 02:52:52 gutteridge Exp $

Fix big-endian builds.

--- src/modules/loaders/loader_argb.c.orig	2020-07-28 18:13:51.000000000 +0000
+++ src/modules/loaders/loader_argb.c
@@ -7,6 +7,10 @@ load2(ImlibImage * im, int load_data)
    int                 w = 0, h = 0, alpha = 0;
    DATA32             *ptr;
    int                 y;
+   
+#ifdef WORDS_BIGENDIAN
+   int                 l;
+#endif
 
    rc = LOAD_FAIL;
 
