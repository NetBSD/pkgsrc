$NetBSD: patch-dnsdist.cc,v 1.3 2018/08/08 15:39:55 fhajny Exp $

Bring arg in sync with the code.

--- dnsdist.cc.orig	2018-07-10 12:43:20.000000000 +0000
+++ dnsdist.cc
@@ -2523,7 +2523,7 @@ try
 #ifdef SO_REUSEPORT
       SSetsockopt(cs->tcpFD, SOL_SOCKET, SO_REUSEPORT, 1);
 #else
-      warnlog("SO_REUSEPORT has been configured on local address '%s' but is not supported", cs.local.toStringWithPort());
+      warnlog("SO_REUSEPORT has been configured on local address '%s' but is not supported", cs->local.toStringWithPort());
 #endif
     }
     if(cs->local.sin4.sin_family == AF_INET6) {
