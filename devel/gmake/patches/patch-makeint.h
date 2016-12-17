$NetBSD: patch-makeint.h,v 1.6 2016/12/17 14:14:06 joerg Exp $

* [SV 43434] Handle NULL returns from ttyname().
* Do not override stack limits by default.
  It can dramatically increase the memory use of multi-threaded programs.

--- makeint.h.orig	2014-10-05 16:24:51.000000000 +0000
+++ makeint.h
@@ -408,9 +408,6 @@ extern int unixy_shell;
 
 #define STOP_SET(_v,_m) ANY_SET (stopchar_map[(unsigned char)(_v)],(_m))
 
-#if defined(HAVE_SYS_RESOURCE_H) && defined(HAVE_GETRLIMIT) && defined(HAVE_SETRLIMIT)
-# define SET_STACK_SIZE
-#endif
 #ifdef SET_STACK_SIZE
 # include <sys/resource.h>
 extern struct rlimit stack_limit;
@@ -424,10 +421,11 @@ extern struct rlimit stack_limit;
 /* The number of bytes needed to represent the largest integer as a string.  */
 #define INTSTR_LENGTH         CSTRLEN ("18446744073709551616")
 
+#define DEFAULT_TTYNAME "true"
 #ifdef HAVE_TTYNAME
 # define TTYNAME(_f) ttyname (_f)
 #else
-# define TTYNAME(_f) "true"
+# define TTYNAME(_f) DEFAULT_TTYNAME
 #endif
 
 
