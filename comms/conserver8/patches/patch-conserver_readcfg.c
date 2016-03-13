$NetBSD: patch-conserver_readcfg.c,v 1.1 2016/03/13 18:31:11 schnoebe Exp $

Have readcfg.c use the same logic as main.c uses for setproctitle.

--- conserver/readcfg.c.orig	2015-06-02 17:19:31.000000000 +0000
+++ conserver/readcfg.c
@@ -5376,7 +5376,14 @@ ReReadCfg(int fd, int msfd)
 		local += pGE->imembers;
 	    for (pRC = pRCList; (REMOTE *)0 != pRC; pRC = pRC->pRCnext)
 		remote++;
-	    setproctitle("master: port %hu, %d local, %d remote", bindPort,
+	    setproctitle("master: port %hu, %d local, %d remote",
+#if USE_IPV6
+			 config->primaryport,
+#elif USE_UNIX_DOMAIN_SOCKETS
+			 0,
+#else
+			 bindPort,
+#endif
 			 local, remote);
 	} else
 	    setproctitle("group %u: port %hu, %d %s", pGroups->id,
