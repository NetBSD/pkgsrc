$NetBSD: patch-src_terminal.h,v 1.1 2026/01/06 21:42:55 wiz Exp $

Include termios.h for struct termios.

--- src/terminal.h.orig	2026-01-06 21:41:47.238819588 +0000
+++ src/terminal.h
@@ -20,6 +20,7 @@
 #define GST123_TERMINAL_H
 
 #include <term.h>
+#include <termios.h>
 #include <glib.h>
 #include <vector>
 #include <string>
