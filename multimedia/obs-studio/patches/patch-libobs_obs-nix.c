$NetBSD: patch-libobs_obs-nix.c,v 1.3 2021/01/12 16:17:47 ryoon Exp $

Support NetBSD.

--- libobs/obs-nix.c.orig	2021-01-04 15:02:53.000000000 +0000
+++ libobs/obs-nix.c
@@ -23,10 +23,10 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #endif
-#if !defined(__OpenBSD__)
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 #include <sys/sysinfo.h>
 #endif
 #include <sys/utsname.h>
@@ -157,7 +157,7 @@ static void log_processor_info(void)
 	dstr_free(&proc_speed);
 	free(line);
 }
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 static void log_processor_speed(void)
 {
 #ifndef __OpenBSD__
@@ -222,7 +222,7 @@ static void log_processor_info(void)
 
 static void log_memory_info(void)
 {
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 	int mib[2];
 	size_t len;
 	int64_t mem;
