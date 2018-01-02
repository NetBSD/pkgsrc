$NetBSD: patch-portsmplexer.cc,v 1.1 2018/01/02 12:23:55 fhajny Exp $

Work around invalid cast to binary operator.

--- portsmplexer.cc.orig	2017-12-04 12:51:03.000000000 +0000
+++ portsmplexer.cc
@@ -85,8 +85,8 @@ int PortsFDMultiplexer::run(struct timev
   }
   
   struct timespec timeoutspec;
-  timeoutspec.tv_sec = time / 1000;
-  timeoutspec.tv_nsec = (time % 1000) * 1000000;
+  timeoutspec.tv_sec = (intptr_t)time / 1000;
+  timeoutspec.tv_nsec = ((intptr_t)time % 1000) * 1000000;
   unsigned int numevents=1;
   int ret= port_getn(d_portfd, d_pevents.get(), min(PORT_MAX_LIST, s_maxevents), &numevents, &timeoutspec);
   
