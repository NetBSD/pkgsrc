$NetBSD: patch-proc.c,v 1.2 2025/10/05 11:04:21 leot Exp $

Add support for QNX.

--- proc.c.orig	2024-02-13 10:16:07.000000000 +0000
+++ proc.c
@@ -33,6 +33,10 @@
 
 #include "tmux.h"
 
+#ifndef SA_RESTART
+# define SA_RESTART 0
+#endif
+
 struct tmuxproc {
 	const char	 *name;
 	int		  exit;
