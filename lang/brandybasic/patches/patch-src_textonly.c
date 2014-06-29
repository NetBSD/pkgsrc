$NetBSD: patch-src_textonly.c,v 1.1 2014/06/29 04:39:58 dholland Exp $

This package for some reason thinks MacOS comes with DOS <conio.h>. It
doesn't.

--- src/textonly.c~	2004-01-26 18:09:25.000000000 +0000
+++ src/textonly.c
@@ -40,7 +40,7 @@
 #include "screen.h"
 #include "keyboard.h"
 
-#if defined(TARGET_WIN32) | defined(TARGET_DJGPP) | defined(TARGET_BCC32) | defined(TARGET_MACOSX)
+#if defined(TARGET_WIN32) | defined(TARGET_DJGPP) | defined(TARGET_BCC32)
 #include "conio.h"
 #else
 #define USE_ANSI	/* Have to use ANSI control sequences, not conio */
