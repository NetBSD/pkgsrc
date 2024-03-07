$NetBSD: patch-src_Mayaqua_Unix.c,v 1.1 2024/03/07 11:48:35 hauke Exp $

*BSD have statvfs

--- src/Mayaqua/Unix.c.orig	2024-03-05 12:27:18.757261333 +0000
+++ src/Mayaqua/Unix.c
@@ -51,6 +51,11 @@
 #include <sys/statvfs.h>
 #endif
 
+#ifdef UNIX_BSD
+#define USE_STATVFS
+#include <sys/statvfs.h>
+#endif
+
 #ifdef	UNIX_MACOS
 #ifdef	NO_VLAN
 // Struct statfs for MacOS X
