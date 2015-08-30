$NetBSD: patch-libyara_proc.c,v 1.2 2015/08/30 08:58:47 dholland Exp $

Add NetBSD support

--- libyara/proc.c.orig	2015-06-06 06:50:32.000000000 +0000
+++ libyara/proc.c
@@ -153,7 +153,8 @@ int yr_process_get_memory(
 #include <yara/mem.h>
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || \
-    defined(__OpenBSD__) || defined(__MACH__)
+    defined(__OpenBSD__) || defined(__MACH__) || defined(__NetBSD__) || \
+    defined(__DragonFly__) || defined(__Bitrig__)
 #define PTRACE_ATTACH PT_ATTACH
 #define PTRACE_DETACH PT_DETACH
 #endif
