$NetBSD: patch-celibc.h,v 1.1 2026/03/17 15:37:36 nia Exp $

We need to include <strings.h> unconditionally since the
code uses bcopy(3).

--- celibc.h.orig	2026-03-17 15:22:49.906827907 +0000
+++ celibc.h
@@ -45,10 +45,10 @@ extern char *mktemp();
 
 #ifdef HAVE_STRING_H
 #  include <string.h>
-#else
-#  include <strings.h>
 #endif
 
+#  include <strings.h>
+
 /*
  * String functions that may or may not be provided by the C library
  */
