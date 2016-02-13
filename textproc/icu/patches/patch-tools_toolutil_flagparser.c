$NetBSD: patch-tools_toolutil_flagparser.c,v 1.1 2016/02/13 20:41:59 bsiegert Exp $

http://bugs.icu-project.org/trac/ticket/11959

Fix build on CentOS 7.

--- tools/toolutil/flagparser.c.orig	2015-10-08 03:54:06.000000000 +0000
+++ tools/toolutil/flagparser.c
@@ -97,7 +97,7 @@ parseFlagsFile_cleanup:
 
     T_FileStream_close(f);
     
-    if (U_FAILURE(*status)) {
+    if (U_FAILURE(*status) && *status != U_BUFFER_OVERFLOW_ERROR) {
         return -1;
     }
 
