$NetBSD: patch-pmap__check.c,v 1.1 2024/04/29 10:11:14 nia Exp $

Eliminate implicit function decls.

--- pmap_check.c.orig	2024-04-29 10:04:26.609849565 +0000
+++ pmap_check.c
@@ -36,16 +36,16 @@ static char sccsid[] = "@(#) pmap_check.
 #endif
 
 #include <rpc/rpc.h>
+#include <rpc/rpcent.h>
 #include <rpc/pmap_prot.h>
+#include <stdio.h>
+#include <stdlib.h>
 #include <syslog.h>
 #include <netdb.h>
+#include <unistd.h>
 #include <sys/signal.h>
-#ifdef SYSV40
+#include <arpa/inet.h>
 #include <netinet/in.h>
-#include <rpc/rpcent.h>
-#endif
-
-extern char *inet_ntoa();
 
 #include "pmap_check.h"
 
