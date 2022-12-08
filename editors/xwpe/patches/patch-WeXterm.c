$NetBSD: patch-WeXterm.c,v 1.1 2022/12/08 10:31:08 vins Exp $

Fix implicit declaration warnings.

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
 
