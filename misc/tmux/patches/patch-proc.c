$NetBSD: patch-proc.c,v 1.1 2025/10/05 10:53:23 js Exp $

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
