$NetBSD: patch-term.c,v 1.1 2013/07/18 12:05:09 joerg Exp $

--- term.c.orig	2002-10-03 16:54:33.000000000 +0000
+++ term.c
@@ -53,6 +53,9 @@
 #endif
 #endif
 
+#include <term.h>
+#include <termios.h>
+
 #undef TRUE
 #undef FALSE
 
