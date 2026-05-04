$NetBSD: patch-jfbuild_src_mmulti.c,v 1.1 2026/05/04 12:28:52 nia Exp $

Build on NetBSD.

--- jfbuild/src/mmulti.c.orig	2026-05-04 10:57:18.118628799 +0000
+++ jfbuild/src/mmulti.c
@@ -911,9 +911,11 @@ static int lookuphost(const char *name, struct sockadd
 	memset(&hints, 0, sizeof(hints));
 	hints.ai_flags = AI_ADDRCONFIG;
 	hints.ai_family = domain;
+#ifdef AI_V4MAPPED
 	if (domain == PF_INET6) {
 		hints.ai_flags |= AI_V4MAPPED;
 	}
+#endif
 	hints.ai_socktype = SOCK_DGRAM;
 	hints.ai_protocol = IPPROTO_UDP;
 
