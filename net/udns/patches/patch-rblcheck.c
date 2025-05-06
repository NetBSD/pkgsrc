$NetBSD: patch-rblcheck.c,v 1.1 2025/05/06 15:20:07 schmonz Exp $

Add missing include.

--- rblcheck.c.orig	Tue May  6 15:15:13 2025
+++ rblcheck.c
@@ -32,6 +32,7 @@
 #else
 # include <unistd.h>
 # include <sys/types.h>
+# include <sys/select.h>
 # include <sys/socket.h>
 # include <netinet/in.h>
 #endif
