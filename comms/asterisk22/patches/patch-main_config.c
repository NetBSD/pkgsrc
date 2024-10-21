$NetBSD: patch-main_config.c,v 1.1 2024/10/21 05:12:46 jnemeth Exp $

--- main/config.c.orig	2024-03-25 05:41:31.131220754 +0000
+++ main/config.c
@@ -44,6 +44,7 @@
 #include <libgen.h>
 #include <time.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 
 #include <math.h>	/* HUGE_VAL */
 #include <regex.h>
