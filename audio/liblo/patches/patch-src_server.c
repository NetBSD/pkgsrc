$NetBSD: patch-src_server.c,v 1.1 2025/12/19 12:46:46 nia Exp $

Fix implicit function declarations.

--- src/server.c.orig	2025-12-19 12:34:19.065063294 +0000
+++ src/server.c
@@ -22,6 +22,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <strings.h>
 #include <ctype.h>
 #include <errno.h>
 #include <float.h>
@@ -59,6 +60,10 @@
 #ifdef HAVE_GETIFADDRS
 #include <ifaddrs.h>
 #endif
+#endif
+
+#if defined(__linux__) || defined(__sun)
+#include <alloca.h>
 #endif
 
 #if defined(WIN32) || defined(_MSC_VER)
