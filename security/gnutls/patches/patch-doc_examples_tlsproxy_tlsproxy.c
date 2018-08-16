$NetBSD: patch-doc_examples_tlsproxy_tlsproxy.c,v 1.1 2018/08/16 11:05:47 wiz Exp $

Improve portability outside Linux.

--- doc/examples/tlsproxy/tlsproxy.c.orig	2018-07-02 18:00:33.000000000 +0000
+++ doc/examples/tlsproxy/tlsproxy.c
@@ -67,7 +67,7 @@ bindtoaddress (char *addrport)
   hints.ai_socktype = SOCK_STREAM;	/* Stream socket */
   hints.ai_protocol = 0;	/* any protocol */
 
-  char *addr = strdupa (addrport);
+  char *addr = strdup (addrport);
   char *colon = strrchr (addr, ':');
   char *port = defaultport;
   if (colon)
@@ -134,7 +134,7 @@ connecttoaddress (char *addrport)
   hints.ai_socktype = SOCK_STREAM;	/* Stream socket */
   hints.ai_protocol = 0;	/* any protocol */
 
-  char *addr = strdupa (addrport);
+  char *addr = strdup (addrport);
   char *colon = strrchr (addr, ':');
   char *port = defaultport;
   if (colon)
