$NetBSD: patch-src_tcp.c,v 1.2 2018/03/23 12:24:32 fhajny Exp $

Improve portability, fix build on SunOS and BSD.

--- src/tcp.c.orig	2018-03-21 08:40:38.000000000 +0000
+++ src/tcp.c
@@ -668,7 +668,7 @@ EnableKeepAlive(const relpTcp_t *__restr
 	if(pSrv->iKeepAliveProbes > 0) {
 		optval = pSrv->iKeepAliveProbes;
 		optlen = sizeof(optval);
-		ret = setsockopt(sock, SOL_TCP, TCP_KEEPCNT, &optval, optlen);
+		ret = setsockopt(sock, IPPROTO_TCP, TCP_KEEPCNT, &optval, optlen);
 	} else {
 		ret = 0;
 	}
@@ -684,7 +684,7 @@ EnableKeepAlive(const relpTcp_t *__restr
 	if(pSrv->iKeepAliveTime > 0) {
 		optval = pSrv->iKeepAliveTime;
 		optlen = sizeof(optval);
-		ret = setsockopt(sock, SOL_TCP, TCP_KEEPIDLE, &optval, optlen);
+		ret = setsockopt(sock, IPPROTO_TCP, TCP_KEEPIDLE, &optval, optlen);
 	} else {
 		ret = 0;
 	}
@@ -700,7 +700,7 @@ EnableKeepAlive(const relpTcp_t *__restr
 	if(pSrv->iKeepAliveIntvl > 0) {
 		optval = pSrv->iKeepAliveIntvl;
 		optlen = sizeof(optval);
-		ret = setsockopt(sock, SOL_TCP, TCP_KEEPINTVL, &optval, optlen);
+		ret = setsockopt(sock, IPPROTO_TCP, TCP_KEEPINTVL, &optval, optlen);
 	} else {
 		ret = 0;
 	}
@@ -1592,7 +1592,7 @@ static inline void
 setCORKopt(int sock, const int onOff)
 {
 #if defined(TCP_CORK)
-	setsockopt(sock, SOL_TCP, TCP_CORK, &onOff, sizeof (onOff));
+	setsockopt(sock, IPPROTO_TCP, TCP_CORK, &onOff, sizeof (onOff));
 #elif defined(TCP_NOPUSH)
 	setsockopt(sock, IPPROTO_TCP, TCP_NOPUSH, &onOff, sizeof (onOff));
 #endif
