$NetBSD: patch-src_fileoperation.c,v 1.1 2013/03/28 21:39:32 joerg Exp $

--- src/fileoperation.c.orig	2013-03-28 20:33:04.000000000 +0000
+++ src/fileoperation.c
@@ -347,7 +347,7 @@ file_operation_copy_do ( const char* src
 
   check_cancel( file_operation );
   if( file_operation->state == FOS_CANCELLED )  {
-    return NULL;
+    return;
   }
 
   file_operation->current_file = src_file;
