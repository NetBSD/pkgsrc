$NetBSD: patch-client.c,v 1.3 2025/10/05 10:53:23 js Exp $

--- client.c.orig	2024-10-02 08:41:47.000000000 +0000
+++ client.c
@@ -32,6 +32,10 @@
 
 #include "tmux.h"
 
+#ifndef SA_RESTART
+# define SA_RESTART 0
+#endif
+
 static struct tmuxproc	*client_proc;
 static struct tmuxpeer	*client_peer;
 static uint64_t		 client_flags;
