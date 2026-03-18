$NetBSD: patch-xpaintrw_readWriteSGI.c,v 1.1 2026/03/18 15:14:35 nia Exp $

Fix implicit function declarations.

--- xpaintrw/readWriteSGI.c.orig	2026-03-18 14:43:21.865503593 +0000
+++ xpaintrw/readWriteSGI.c
@@ -16,2 +16,3 @@
 
+#include <fcntl.h>
 #include <unistd.h>
