$NetBSD: patch-src_base64.c,v 1.1 2026/03/21 10:38:34 nia Exp $

Fix implicit function declarations.

--- src/base64.c.orig	2001-06-16 17:06:56.000000000 +0000
+++ src/base64.c
@@ -9,6 +9,8 @@
 
 /* System includes */
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #if !defined(PLATFORM_WINNT) && !defined(PLATFORM_BEOS)
   #include <syslog.h>
 #endif
