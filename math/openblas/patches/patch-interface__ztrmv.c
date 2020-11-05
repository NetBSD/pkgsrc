$NetBSD: patch-interface__ztrmv.c,v 1.1 2020/11/05 16:31:45 bacon Exp $

Avoid buffer overflow

--- interface/ztrmv.c.orig	2016-09-01 03:58:42 UTC
+++ interface/ztrmv.c
@@ -242,7 +242,7 @@ void CNAME(enum CBLAS_ORDER order, enum 
   else
 #endif
   {
-    buffer_size = ((n - 1) / DTB_ENTRIES) * 2 * DTB_ENTRIES + 32 / sizeof(FLOAT);
+    buffer_size = (((n - 1) / DTB_ENTRIES) * 2 * DTB_ENTRIES + 32 / sizeof(FLOAT)) + 8;
     // It seems to be required for some K8 or Barcelona CPU
     buffer_size += 8;
     if(incx != 1)
