$NetBSD: patch-main_config.c,v 1.1 2024/02/19 05:59:52 jnemeth Exp $

--- main/config.c.orig	2024-02-12 05:14:56.251989318 +0000
+++ main/config.c
@@ -44,6 +44,9 @@
 #include <libgen.h>
 #include <time.h>
 #include <sys/stat.h>
+#if HAVE_SYS_WAIT_H
+#include <sys/wait.h>
+#endif
 
 #include <math.h>	/* HUGE_VAL */
 #include <regex.h>
