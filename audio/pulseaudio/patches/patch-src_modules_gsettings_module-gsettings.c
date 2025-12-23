$NetBSD: patch-src_modules_gsettings_module-gsettings.c,v 1.1 2025/12/23 10:47:19 adam Exp $

Include signal.h for kill().

--- src/modules/gsettings/module-gsettings.c.orig	2025-12-23 10:42:59.682351708 +0000
+++ src/modules/gsettings/module-gsettings.c
@@ -23,6 +23,7 @@
 
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 #include <pulsecore/core-error.h>
 #include <pulsecore/core-util.h>
