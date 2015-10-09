$NetBSD: patch-src_c_src_zookeeper.c,v 1.1 2015/10/09 13:59:56 fhajny Exp $

Fix array reference.
--- src/c/src/zookeeper.c.orig	2014-02-20 10:14:09.000000000 +0000
+++ src/c/src/zookeeper.c
@@ -570,7 +570,7 @@ int getaddrs(zhandle_t *zh)
         hints.ai_socktype = SOCK_STREAM;
         hints.ai_protocol = IPPROTO_TCP;
 
-        while(isspace(*host) && host != strtok_last)
+        while(isspace((unsigned char) *host) && host != strtok_last)
             host++;
 
         if ((rc = getaddrinfo(host, port_spec, &hints, &res0)) != 0) {
