$NetBSD: patch-client.c,v 1.2 2026/01/22 10:10:19 wiz Exp $

NetBSD provides libedit-as-readline, but chrony wants libedit.
just include the fake readline header.

--- client.c.orig	2025-08-27 12:05:31.000000000 +0000
+++ client.c
@@ -44,7 +44,7 @@
 #include "util.h"
 
 #ifdef FEAT_READLINE
-#include <editline/readline.h>
+#include <readline.h>
 #endif
 
 #define MAX_UNIX_SOCKET_LENGTH (sizeof ((struct sockaddr_un *)NULL)->sun_path)
