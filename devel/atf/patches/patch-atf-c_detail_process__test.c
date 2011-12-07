$NetBSD: patch-atf-c_detail_process__test.c,v 1.1 2011/12/07 17:23:05 bsiegert Exp $

--- atf-c/detail/process_test.c.orig	Sun Aug 21 01:01:24 2011
+++ atf-c/detail/process_test.c
@@ -28,8 +28,8 @@
  */
 
 #include <sys/types.h>
-#include <sys/resource.h>
 #include <sys/time.h>
+#include <sys/resource.h>
 #include <sys/wait.h>
 
 #include <errno.h>
