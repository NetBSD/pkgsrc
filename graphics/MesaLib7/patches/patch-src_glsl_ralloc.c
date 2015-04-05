$NetBSD: patch-src_glsl_ralloc.c,v 1.1 2015/04/05 17:01:37 tnn Exp $

* Fix exit time segfault of qt5 application with modular xorg

--- src/glsl/ralloc.c.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/glsl/ralloc.c
@@ -272,7 +272,7 @@ ralloc_parent(const void *ptr)
 
 static void *autofree_context = NULL;
 
-static void
+static void __attribute__((__destructor__))
 autofree(void)
 {
    ralloc_free(autofree_context);
@@ -283,7 +283,6 @@ ralloc_autofree_context(void)
 {
    if (unlikely(autofree_context == NULL)) {
       autofree_context = ralloc_context(NULL);
-      atexit(autofree);
    }
    return autofree_context;
 }
