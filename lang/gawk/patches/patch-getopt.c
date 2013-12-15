$NetBSD: patch-getopt.c,v 1.1 2013/12/15 09:42:14 richard Exp $

SunOS needs stdlib.h for malloc/free used in p_getopt_internal_r

--- getopt.c.orig	2013-05-02 19:51:30.000000000 +0000
+++ getopt.c
@@ -57,7 +57,7 @@
 
 /* This needs to come after some library #include
    to get __GNU_LIBRARY__ defined.  */
-#if defined (__GNU_LIBRARY__) || defined (__CYGWIN__) || defined(__DJGPP__)
+#if defined (__GNU_LIBRARY__) || defined (__CYGWIN__) || defined(__DJGPP__) || defined(__sun)
 /* Don't include stdlib.h for
  * non-GNU C libraries
  * non-Cygwin
