$NetBSD: patch-lib.h,v 1.1 2020/11/08 17:42:46 tron Exp $

On some systems, curses.h defines TRUE and FALSE, so conditionalise
them here to avoid compiler complaints about duplicate definitions.

--- lib.h.orig	2020-11-03 17:50:37.000000000 +0000
+++ lib.h	2020-11-08 15:01:50.511710523 +0000
@@ -54,8 +54,12 @@
 #  define N_(a) a
 # endif
 
-# define TRUE 1
-# define FALSE 0
+# ifndef TRUE
+#  define TRUE 1
+# endif
+# ifndef FALSE
+#  define FALSE 0
+# endif
 
 # define HUGE_STRING        8192
 # define LONG_STRING        1024
