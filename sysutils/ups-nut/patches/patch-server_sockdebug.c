$NetBSD: patch-server_sockdebug.c,v 1.1 2023/11/09 18:01:06 gdt Exp $

Work around upstream bug of including libwrap  on a test program not written for tcp wrappers.

Reported upstream by email 20231109.

--- server/sockdebug.c.orig	2023-09-17 14:34:05.000000000 +0000
+++ server/sockdebug.c
@@ -32,6 +32,12 @@
 #include "parseconf.h"
 #include "nut_stdint.h"
 
+#ifdef HAVE_WRAP
+#include <tcpd.h>
+int	allow_severity = LOG_INFO;
+int	deny_severity = LOG_WARNING;
+#endif	/* HAVE_WRAP */
+
 static PCONF_CTX_t	sock_ctx;
 
 static void sock_arg(size_t numarg, char **arg)
