$NetBSD: patch-app_base_base-utils.c,v 1.1 2012/05/07 08:40:08 adam Exp $

--- app/base/base-utils.c.orig	2012-05-07 07:50:39.000000000 +0000
+++ app/base/base-utils.c
@@ -33,8 +33,10 @@
 /* For get_backtrace() */
 #include <stdlib.h>
 #include <string.h>
+#ifdef __linux__
 #include <execinfo.h>
 #endif
+#endif
 
 #include "base-utils.h"
 
@@ -112,7 +114,7 @@ get_physical_memory_size (void)
 char *
 get_backtrace (void)
 {
-#ifdef G_OS_UNIX
+#ifdef __linux__
   void     *functions[MAX_FUNC];
   char    **function_names;
   int       n_functions;
