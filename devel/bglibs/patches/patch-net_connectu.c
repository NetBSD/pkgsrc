$NetBSD: patch-net_connectu.c,v 1.1 2025/12/20 12:29:24 nia Exp $

Include missing header for strcpy(3).

--- net/connectu.c.orig	2025-12-20 12:05:26.502790967 +0000
+++ net/connectu.c
@@ -21,6 +21,7 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <unistd.h>
+#include <string.h>
 #include "socket.h"
 
 /** Make an UNIX domain connection. */
