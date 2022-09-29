$NetBSD: patch-portsmplexer.cc,v 1.4 2022/09/29 12:47:31 jperkin Exp $

Fix build on SunOS.

--- portsmplexer.cc.orig	2022-09-19 10:31:34.000000000 +0000
+++ portsmplexer.cc
@@ -39,9 +39,9 @@ private:
   std::vector<port_event_t> d_pevents;
 };
 
-static FDMultiplexer* makePorts(unsigned int)
+static FDMultiplexer* makePorts(unsigned int maxEventsHint)
 {
-  return new PortsFDMultiplexer();
+  return new PortsFDMultiplexer(maxEventsHint);
 }
 
 static struct PortsRegisterOurselves
@@ -94,7 +94,7 @@ void PortsFDMultiplexer::getAvailableFDs
   timeoutspec.tv_sec = timeout / 1000;
   timeoutspec.tv_nsec = (timeout % 1000) * 1000000;
   unsigned int numevents = 1;
-  int ret = port_getn(d_portfd, d_pevents.data(), min(PORT_MAX_LIST, d_pevents.size()), &numevents, &timeoutspec);
+  int ret = port_getn(d_portfd, d_pevents.data(), min(PORT_MAX_LIST, static_cast<int>(d_pevents.size())), &numevents, &timeoutspec);
 
   /* port_getn has an unusual API - (ret == -1, errno == ETIME) can
      mean partial success; you must check (*numevents) in this case
@@ -155,7 +155,7 @@ int PortsFDMultiplexer::run(struct timev
   timeoutspec.tv_sec = timeout / 1000;
   timeoutspec.tv_nsec = (timeout % 1000) * 1000000;
   unsigned int numevents = 1;
-  int ret = port_getn(d_portfd, d_pevents.data(), min(PORT_MAX_LIST, d_pevents.size()), &numevents, &timeoutspec);
+  int ret = port_getn(d_portfd, d_pevents.data(), min(PORT_MAX_LIST, static_cast<int>(d_pevents.size())), &numevents, &timeoutspec);
 
   /* port_getn has an unusual API - (ret == -1, errno == ETIME) can
      mean partial success; you must check (*numevents) in this case
