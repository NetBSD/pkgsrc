$NetBSD: patch-src_glsl_ralloc.c,v 1.3 2015/04/25 11:19:18 tnn Exp $

* Fix exit time segfault of qt5 application with modular xorg

--- src/util/ralloc.c.orig	2014-10-03 03:59:51.000000000 +0000
+++ src/util/ralloc.c
@@ -285,7 +285,7 @@ ralloc_parent(const void *ptr)
 
 static void *autofree_context = NULL;
 
-static void
+static void __attribute__((__destructor__))
 autofree(void)
 {
    ralloc_free(autofree_context);
@@ -296,7 +296,6 @@ ralloc_autofree_context(void)
 {
    if (unlikely(autofree_context == NULL)) {
       autofree_context = ralloc_context(NULL);
-      atexit(autofree);
    }
    return autofree_context;
 }
