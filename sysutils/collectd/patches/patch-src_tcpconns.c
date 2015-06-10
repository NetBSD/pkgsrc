$NetBSD: patch-src_tcpconns.c,v 1.4 2015/06/10 20:05:26 fhajny Exp $

--- src/tcpconns.c.orig	2015-05-20 12:04:47.191035542 +0000
+++ src/tcpconns.c
@@ -948,6 +948,7 @@ static int conn_init (void)
   return (0);
 } /* int conn_init */
 
+#include <sys/param.h>
 static int conn_read (void)
 {
   struct inpcbtable table;
