$NetBSD: patch-main_config.c,v 1.1 2024/10/26 13:12:23 ryoon Exp $

--- main/config.c.orig	2024-10-26 12:10:13.346969822 +0000
+++ main/config.c
@@ -44,6 +44,7 @@
 #include <libgen.h>
 #include <time.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 
 #include <math.h>	/* HUGE_VAL */
 #include <regex.h>
