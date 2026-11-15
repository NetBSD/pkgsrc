$NetBSD: patch-WeXterm.c,v 1.2 2026/11/15 13:14:45 vins Exp $

Prevent implicit declaration of e_X_sw_color().

--- WeXterm.c.orig	2005-07-07 01:53:09.000000000 +0000
+++ WeXterm.c
@@ -37,6 +37,13 @@
 #endif
 #endif
 
+#ifndef __WE_XTERM_H
+#define __WE_XTERM_H
+
+int e_X_sw_color(void);
+
+#endif
+
 /* Information from X that is needed throughout execution */
 WpeXStruct WpeXInfo;
 
