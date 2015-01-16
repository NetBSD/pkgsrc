$NetBSD: patch-plugins_imptcp_imptcp.c,v 1.1 2015/01/16 16:58:28 fhajny Exp $

Improve portability, fix build on SunOS and BSD.
--- plugins/imptcp/imptcp.c.orig	2015-01-08 14:58:14.000000000 +0000
+++ plugins/imptcp/imptcp.c
@@ -585,7 +585,7 @@ EnableKeepAlive(ptcplstn_t *pLstn, int s
 	if(pLstn->pSrv->iKeepAliveProbes > 0) {
 		optval = pLstn->pSrv->iKeepAliveProbes;
 		optlen = sizeof(optval);
-		ret = setsockopt(sock, SOL_TCP, TCP_KEEPCNT, &optval, optlen);
+		ret = setsockopt(sock, IPPROTO_TCP, TCP_KEEPCNT, &optval, optlen);
 	} else {
 		ret = 0;
 	}
@@ -600,7 +600,7 @@ EnableKeepAlive(ptcplstn_t *pLstn, int s
 	if(pLstn->pSrv->iKeepAliveTime > 0) {
 		optval = pLstn->pSrv->iKeepAliveTime;
 		optlen = sizeof(optval);
-		ret = setsockopt(sock, SOL_TCP, TCP_KEEPIDLE, &optval, optlen);
+		ret = setsockopt(sock, IPPROTO_TCP, TCP_KEEPIDLE, &optval, optlen);
 	} else {
 		ret = 0;
 	}
@@ -615,7 +615,7 @@ EnableKeepAlive(ptcplstn_t *pLstn, int s
 	if(pLstn->pSrv->iKeepAliveIntvl > 0) {
 		optval = pLstn->pSrv->iKeepAliveIntvl;
 		optlen = sizeof(optval);
-		ret = setsockopt(sock, SOL_TCP, TCP_KEEPINTVL, &optval, optlen);
+		ret = setsockopt(sock, IPPROTO_TCP, TCP_KEEPINTVL, &optval, optlen);
 	} else {
 		ret = 0;
 	}
