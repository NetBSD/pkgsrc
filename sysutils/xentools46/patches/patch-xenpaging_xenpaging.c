$NetBSD: patch-xenpaging_xenpaging.c,v 1.1.1.1 2016/07/04 07:30:51 jnemeth Exp $

--- xenpaging/xenpaging.c.orig	2016-06-20 12:08:22.000000000 +0000
+++ xenpaging/xenpaging.c
@@ -182,10 +182,11 @@ static int xenpaging_get_tot_pages(struc
 static void *init_page(void)
 {
     void *buffer;
+    int rc;
 
     /* Allocated page memory */
-    errno = posix_memalign(&buffer, PAGE_SIZE, PAGE_SIZE);
-    if ( errno != 0 )
+    rc = posix_memalign(&buffer, PAGE_SIZE, PAGE_SIZE);
+    if ( rc != 0 )
         return NULL;
 
     /* Lock buffer in memory so it can't be paged out */
