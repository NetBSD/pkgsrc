$NetBSD: patch-src_glsl_ralloc.c,v 1.1 2014/01/24 23:00:15 ryoon Exp $

* Fix exit time segfault of qt5 application with modular xorg

--- src/glsl/ralloc.c.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/glsl/ralloc.c
@@ -283,7 +283,8 @@ ralloc_autofree_context(void)
 {
    if (unlikely(autofree_context == NULL)) {
       autofree_context = ralloc_context(NULL);
-      atexit(autofree);
+      extern __attribute__((visibility("hidden"))) void *__dso_handle;
+      __cxa_atexit(autofree, NULL, __dso_handle);
    }
    return autofree_context;
 }
