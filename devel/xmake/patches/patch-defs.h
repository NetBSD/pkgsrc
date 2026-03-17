$NetBSD: patch-defs.h,v 1.1 2026/03/17 15:38:32 nia Exp $

Fix implicit declaration of bcopy(3).

--- defs.h.orig	2026-03-17 15:18:43.496369848 +0000
+++ defs.h
@@ -14,6 +14,7 @@
 #include <stddef.h>
 #include <stdarg.h>
 #include <string.h>
+#include <strings.h>
 #include <unistd.h>
 
 #define Prototype	extern
