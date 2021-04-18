$NetBSD: patch-tools_xenpaging_xenpaging.c,v 1.1 2021/04/18 12:31:26 bouyer Exp $

Fix "error: 'buffer' may be used uninitialized"

--- tools/xenpaging/xenpaging.c.orig	2021-04-17 14:43:41.053494277 +0200
+++ tools/xenpaging/xenpaging.c	2021-04-17 14:44:17.167271008 +0200
@@ -180,7 +180,7 @@
 
 static void *init_page(void)
 {
-    void *buffer;
+    void *buffer = NULL; /* XXX gcc */
 
     /* Allocated page memory */
     errno = posix_memalign(&buffer, XC_PAGE_SIZE, XC_PAGE_SIZE);
