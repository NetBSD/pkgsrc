$NetBSD: patch-mpcenc_keyboard.c,v 1.1 2014/04/18 12:43:42 wiz Exp $

Add header for struct timeval.

--- mpcenc/keyboard.c.orig	2006-12-19 19:39:02.000000000 +0000
+++ mpcenc/keyboard.c
@@ -52,6 +52,8 @@ CheckKey ( void )
 
 #else
 
+#include <sys/time.h>
+
 # ifdef USE_TERMIOS
 #  include <termios.h>
 
