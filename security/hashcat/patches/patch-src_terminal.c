$NetBSD: patch-src_terminal.c,v 1.1 2022/01/10 02:30:23 khorben Exp $

Fix the build for FreeBSD and NetBSD

--- src/terminal.c.orig	2021-11-21 15:39:01.000000000 +0000
+++ src/terminal.c
@@ -439,7 +439,7 @@ void SetConsoleWindowSize (const int x)
 }
 #endif
 
-#if defined (__linux__) || defined (__CYGWIN__)
+#if defined (__FreeBSD__) || defined (__NetBSD__) || defined (__linux__) || defined (__CYGWIN__)
 static struct termios savemodes;
 static int havemodes = 0;
 
