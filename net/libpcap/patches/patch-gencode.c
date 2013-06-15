$NetBSD: patch-gencode.c,v 1.2 2013/06/15 21:01:22 adam Exp $

* Correctly limit Linux interfaces to Linux-only.

--- gencode.c.orig	2012-06-12 16:55:36.000000000 +0000
+++ gencode.c
@@ -84,7 +84,7 @@ static const char rcsid[] _U_ =
 #include "pcap/sll.h"
 #include "pcap/ipnet.h"
 #include "arcnet.h"
-#if defined(PF_PACKET) && defined(SO_ATTACH_FILTER)
+#if defined(linux) && defined(PF_PACKET) && defined(SO_ATTACH_FILTER)
 #include <linux/types.h>
 #include <linux/if_packet.h>
 #include <linux/filter.h>
@@ -7533,7 +7533,7 @@ gen_inbound(dir)
 		 * check it, otherwise give up as this link-layer type
 		 * has nothing in the packet data.
 		 */
-#if defined(PF_PACKET) && defined(SO_ATTACH_FILTER)
+#if defined(linux) && defined(PF_PACKET) && defined(SO_ATTACH_FILTER)
 		/*
 		 * We infer that this is Linux with PF_PACKET support.
 		 * If this is a *live* capture, we can look at
