$NetBSD: patch-src_DivertInterface.cpp,v 1.1 2016/07/01 04:51:15 adam Exp $

Fix for undefined IPPROTO_DIVERT.

--- src/DivertInterface.cpp.orig	2016-06-29 10:56:38.000000000 +0000
+++ src/DivertInterface.cpp
@@ -82,6 +82,9 @@ DivertInterface::DivertInterface(const c
   
   port = atoi(&name[7]);
 
+#ifndef IPPROTO_DIVERT
+#define IPPROTO_DIVERT 254
+#endif
   if((sock = socket(PF_INET, SOCK_RAW, IPPROTO_DIVERT)) == -1) {
     ntop->getTrace()->traceEvent(TRACE_ERROR, "Unable to created divert socket");
     throw 1;
