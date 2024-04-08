$NetBSD: patch-main_config.c,v 1.1 2024/04/08 03:20:08 jnemeth Exp $

--- main/config.c.orig	2024-03-25 05:41:31.131220754 +0000
+++ main/config.c
@@ -44,6 +44,7 @@
 #include <libgen.h>
 #include <time.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 
 #include <math.h>	/* HUGE_VAL */
 #include <regex.h>
