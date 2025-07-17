$NetBSD: patch-gcc_ada_terminals.c,v 1.1 2025/07/17 05:00:17 dkazankov Exp $

openpty defined in <util.h> on NetBSD

--- gcc/ada/terminals.c.orig	2025-04-25 08:18:00.000000000 +0000
+++ gcc/ada/terminals.c
@@ -1122,7 +1122,7 @@
 #if defined (__hpux__)
 #   include <sys/stropts.h>
 #endif
-#if defined (__APPLE__)
+#if defined (__APPLE__) || defined (__NetBSD__)
 #   include <util.h>
 #endif
 #if defined (__FreeBSD__)
