$NetBSD: patch-gcc_ada_terminals.c,v 1.1 2025/04/25 19:35:10 dkazankov Exp $

openpty defined in <util.h> on NetBSD

--- gcc/ada/terminals.c.orig	2024-05-07 09:51:37.000000000 +0300
+++ gcc/ada/terminals.c	2024-08-01 10:53:08.600527021 +0300
@@ -1122,7 +1122,7 @@
 #if defined (__hpux__)
 #   include <sys/stropts.h>
 #endif
-#if defined (__APPLE__)
+#if defined (__APPLE__) || defined (__NetBSD__)
 #   include <util.h>
 #endif
 #if defined (__FreeBSD__)
