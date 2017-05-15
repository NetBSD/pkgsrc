$NetBSD: patch-courier_module.esmtp_esmtpclient.c,v 1.1 2017/05/15 13:06:48 jperkin Exp $

Compat define for SOL_TCP.

--- courier/module.esmtp/esmtpclient.c.orig	2012-04-23 17:11:48.000000000 +0000
+++ courier/module.esmtp/esmtpclient.c
@@ -79,6 +79,9 @@ static time_t quit_timeout;
 static time_t data_timeout;
 
 #ifdef	TCP_CORK
+#ifndef SOL_TCP
+#define SOL_TCP	IPPROTO_TCP
+#endif
 
 static int esmtp_cork;
 static int corked;
