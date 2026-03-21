$NetBSD: patch-include_sub.h,v 1.1 2026/03/21 09:44:45 nia Exp $

Fix implicit decl of string functions.

--- include/sub.h.orig	2026-03-21 09:20:30.346319589 +0000
+++ include/sub.h
@@ -21,6 +21,8 @@
 #endif
 #include <sys/socket.h>
 #include <net/if.h>
+#include <string.h>
+#include <strings.h>
 
 #ifdef PACKAGE
 #define NAME PACKAGE
