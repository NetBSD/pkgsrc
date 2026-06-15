$NetBSD: patch-lib_pm.h,v 1.1 2026/06/15 07:03:01 nia Exp $

Add missing include for exit(3), atoi(3), used in various
programs. Avoid implicit function declarations.

--- lib/pm.h.orig	2026-06-15 06:59:52.568563162 +0000
+++ lib/pm.h
@@ -18,6 +18,7 @@
 #include <sys/types.h>
 #include <ctype.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <errno.h>
 #include <setjmp.h>
 #include <sys/stat.h>
