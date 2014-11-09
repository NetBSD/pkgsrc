$NetBSD: patch-makeint.h,v 1.1 2014/11/09 03:22:57 obache Exp $

* [SV 43434] Handle NULL returns from ttyname().

--- makeint.h.orig	2014-10-05 16:24:51.000000000 +0000
+++ makeint.h
@@ -424,10 +424,11 @@ extern struct rlimit stack_limit;
 /* The number of bytes needed to represent the largest integer as a string.  */
 #define INTSTR_LENGTH         CSTRLEN ("18446744073709551616")
 
+#define DEFAULT_TTYNAME "true"
 #ifdef HAVE_TTYNAME
 # define TTYNAME(_f) ttyname (_f)
 #else
-# define TTYNAME(_f) "true"
+# define TTYNAME(_f) DEFAULT_TTYNAME
 #endif
 
 
