$NetBSD: patch-runtime_nsd__ptcp.c,v 1.1 2015/01/16 16:58:28 fhajny Exp $

Improve portability, fix build on SunOS and BSD.
--- runtime/nsd_ptcp.c.orig	2015-01-08 14:58:14.000000000 +0000
+++ runtime/nsd_ptcp.c
@@ -656,7 +656,7 @@ EnableKeepAlive(nsd_t *pNsd)
 	if(pThis->iKeepAliveProbes > 0) {
 		optval = pThis->iKeepAliveProbes;
 		optlen = sizeof(optval);
-		ret = setsockopt(pThis->sock, SOL_TCP, TCP_KEEPCNT, &optval, optlen);
+		ret = setsockopt(pThis->sock, IPPROTO_TCP, TCP_KEEPCNT, &optval, optlen);
 	} else {
 		ret = 0;
 	}
@@ -671,7 +671,7 @@ EnableKeepAlive(nsd_t *pNsd)
 	if(pThis->iKeepAliveTime > 0) {
 		optval = pThis->iKeepAliveTime;
 		optlen = sizeof(optval);
-		ret = setsockopt(pThis->sock, SOL_TCP, TCP_KEEPIDLE, &optval, optlen);
+		ret = setsockopt(pThis->sock, IPPROTO_TCP, TCP_KEEPIDLE, &optval, optlen);
 	} else {
 		ret = 0;
 	}
@@ -686,7 +686,7 @@ EnableKeepAlive(nsd_t *pNsd)
 	if(pThis->iKeepAliveIntvl > 0) {
 		optval = pThis->iKeepAliveIntvl;
 		optlen = sizeof(optval);
-		ret = setsockopt(pThis->sock, SOL_TCP, TCP_KEEPINTVL, &optval, optlen);
+		ret = setsockopt(pThis->sock, IPPROTO_TCP, TCP_KEEPINTVL, &optval, optlen);
 	} else {
 		ret = 0;
 	}
