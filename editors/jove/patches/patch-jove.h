$NetBSD: patch-jove.h,v 1.2 2019/09/06 15:53:42 christos Exp $

- modern os's need time.h for time(3)

--- jove.h.orig	2015-10-15 14:21:55.000000000 -0400
+++ jove.h	2019-09-06 11:49:09.552268238 -0400
@@ -18,8 +18,8 @@
 # include <sys/types.h>
 #else
 # include <types.h>
-# include <time.h>	/* for time_t */
 #endif
+#include <time.h>	/* for time_t */
 
 /* proto: macro to allow us to prototype any function declaration
  * without upsetting old compilers.
