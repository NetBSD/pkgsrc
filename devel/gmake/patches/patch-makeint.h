$NetBSD: patch-makeint.h,v 1.8 2018/07/04 14:09:07 bsiegert Exp $

* Do not override stack limits by default.
  It can dramatically increase the memory use of multi-threaded programs.

--- makeint.h.orig	2016-05-21 20:22:32.000000000 +0000
+++ makeint.h
@@ -442,9 +442,6 @@ extern int unixy_shell;
 #define NEXT_TOKEN(s)   while (ISSPACE (*(s))) ++(s)
 #define END_OF_TOKEN(s) while (! STOP_SET (*(s), MAP_SPACE|MAP_NUL)) ++(s)
 
-#if defined(HAVE_SYS_RESOURCE_H) && defined(HAVE_GETRLIMIT) && defined(HAVE_SETRLIMIT)
-# define SET_STACK_SIZE
-#endif
 #ifdef SET_STACK_SIZE
 # include <sys/resource.h>
 extern struct rlimit stack_limit;
