$NetBSD: patch-tools_rpmuncompress.c,v 1.1 2025/02/07 15:06:19 adam Exp $

Add missing include to fix build.

--- tools/rpmuncompress.c.orig	2025-02-07 14:47:31.776517749 +0000
+++ tools/rpmuncompress.c
@@ -1,5 +1,6 @@
 #include "system.h"
 
+#include <sys/wait.h>
 #include <popt.h>
 #include <libgen.h>
 #include <errno.h>
