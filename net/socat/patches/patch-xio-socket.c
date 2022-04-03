$NetBSD: patch-xio-socket.c,v 1.1 2022/04/03 10:29:41 riastradh Exp $

Fix ctype(3) abuse.

--- xio-socket.c.orig	2021-01-03 18:23:22.000000000 +0000
+++ xio-socket.c
@@ -1595,7 +1595,7 @@ int retropt_socket_pf(struct opt *opts, 
    char *pfname;
 
    if (retropt_string(opts, OPT_PROTOCOL_FAMILY, &pfname) >= 0) {
-      if (isdigit(pfname[0])) {
+      if (isdigit((unsigned char)pfname[0])) {
 	 *pf = strtoul(pfname, NULL /*!*/, 0);
 #if WITH_IP4
       } else if (!strcasecmp("inet", pfname) ||
