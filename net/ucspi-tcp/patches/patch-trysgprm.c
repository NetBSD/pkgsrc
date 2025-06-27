$NetBSD: patch-trysgprm.c,v 1.1 2025/06/27 17:18:18 schmonz Exp $

Find sigprocmask on Illumos when in C89 mode.

--- trysgprm.c.orig	2025-06-25 17:36:33.642486035 +0000
+++ trysgprm.c
@@ -1,3 +1,4 @@
+#define _POSIX_C_SOURCE 1
 #include <signal.h>
 
 main()
