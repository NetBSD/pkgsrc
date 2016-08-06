$NetBSD: patch-xenpaging_xenpaging.c,v 1.1 2016/08/06 12:41:36 spz Exp $

--- xenpaging/xenpaging.c.orig	2016-03-23 13:57:27.000000000 +0000
+++ xenpaging/xenpaging.c
@@ -184,6 +184,9 @@ static void *init_page(void)
 {
     void *buffer;
 
+    buffer = NULL; /* shut up compiler about uninitialized use:
+                    * posix_memalign initializes it */
+
     /* Allocated page memory */
     errno = posix_memalign(&buffer, PAGE_SIZE, PAGE_SIZE);
     if ( errno != 0 )
