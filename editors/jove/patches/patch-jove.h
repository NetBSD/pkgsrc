$NetBSD: patch-jove.h,v 1.1 2019/09/02 08:53:32 christos Exp $

- modern os's need time.h for time(3)

--- jove.h.orig	2015-10-15 14:21:55.000000000 -0400
+++ jove.h	2019-09-02 04:39:50.417825060 -0400
@@ -16,6 +16,7 @@
 
 #ifndef MAC
 # include <sys/types.h>
+# include <time.h>
 #else
 # include <types.h>
 # include <time.h>	/* for time_t */
