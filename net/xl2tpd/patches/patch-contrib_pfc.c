$NetBSD: patch-contrib_pfc.c,v 1.1 2013/07/02 00:22:17 christos Exp $

We need ppp_defs.h too

--- contrib/pfc.c	2013-06-17 06:17:24.000000000 -0400
+++ contrib/pfc.c	2013-06-11 19:51:32.000000000 -0400
@@ -14,7 +14,7 @@
 # include <pcap-bpf.h>
 #endif
 
-#ifdef OPENBSD
+#if defined(OPENBSD) || defined(NETBSD)
 # include <net/ppp_defs.h>
 #endif
 
