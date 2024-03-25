$NetBSD: patch-main_config.c,v 1.2 2024/03/25 03:36:33 jnemeth Exp $

--- main/config.c.orig	2024-03-18 13:18:36.000000000 +0000
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
