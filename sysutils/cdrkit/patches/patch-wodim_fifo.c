$NetBSD: patch-wodim_fifo.c,v 1.1 2026/09/22 08:05:41 ryoon Exp $

--- wodim/fifo.c.orig	2026-08-22 09:00:27.176244309 +0000
+++ wodim/fifo.c
@@ -96,6 +96,7 @@
 #include <standard.h>
 #include <errno.h>
 #include <signal.h>
+#include <sys/wait.h>
 #include <libport.h>
 #include <schily.h>
 
