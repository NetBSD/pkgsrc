$NetBSD: patch-src_old_main_emul.cc,v 1.1 2020/10/07 00:43:05 thorpej Exp $

Add support for tap(4)-based networking.

--- src/old_main/emul.cc.orig	2020-10-05 23:04:14.559513959 +0000
+++ src/old_main/emul.cc	2020-10-05 23:04:26.418738637 +0000
@@ -748,6 +748,7 @@ void emul_simple_init(struct emul *emul)
 
 	/*  Create a simple network:  */
 	emul->net = net_init(emul, NET_INIT_FLAG_GATEWAY,
+	    NULL,
 	    NET_DEFAULT_IPV4_MASK,
 	    NET_DEFAULT_IPV4_LEN,
 	    NULL, 0, 0, NULL);
