$NetBSD: patch-src_tcpconns.c,v 1.5 2015/08/11 13:19:21 he Exp $

Include <sys/param.h>

--- src/tcpconns.c.orig	2015-05-20 12:04:47.191035542 +0000
+++ src/tcpconns.c
@@ -948,6 +948,7 @@ static int conn_init (void)
   return (0);
 } /* int conn_init */
 
+#include <sys/param.h>
 static int conn_read (void)
 {
   struct inpcbtable table;
