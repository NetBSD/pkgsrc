$NetBSD: patch-hostfs.c,v 1.1 2013/11/10 12:50:19 ryoon Exp $

* Fix build on NetBSD, functionality is not tested.

--- hostfs.c.orig	2012-10-21 14:43:19.000000000 +0000
+++ hostfs.c
@@ -35,7 +35,7 @@
 #include <dirent.h>
 #include <unistd.h>
 #endif
-#if defined __unix || defined __MACH__ || defined __riscos__
+#if defined __unix || defined __MACH__ || defined __riscos__ || defined __NetBSD__
 #include <utime.h>
 #else
 #include <sys/utime.h>
@@ -72,6 +72,10 @@ int __riscosify_control = 0;
 
 #endif /* !__riscos__ */
 
+#if defined __NetBSD__
+#define NO_OPEN64
+#endif
+
 #include "hostfs.h"
 
 #if defined NO_OPEN64 || defined __MACH__
