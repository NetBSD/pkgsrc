$NetBSD: patch-third-party_miniupnp_miniupnp.c,v 1.1 2013/03/02 19:33:29 wiz Exp $

FreeBSD does IP_MULTICAST_IF, but it is the only BSD that does.
Add DragonFly to the list of system that exclude support for IP multicast

--- third-party/miniupnp/miniupnpc.c.orig	2012-07-06 01:26:19.715654000 +0000
+++ third-party/miniupnp/miniupnpc.c
@@ -17,7 +17,7 @@
 #endif
 #endif
 
-#if !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(MACOSX) && !defined(_WIN32) && !defined(__CYGWIN__) && !defined(__sun)
+#if !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(MACOSX) && !defined(_WIN32) && !defined(__CYGWIN__) && !defined(__sun)
 #define HAS_IP_MREQN
 #endif
 
