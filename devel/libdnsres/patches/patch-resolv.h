$NetBSD: patch-resolv.h,v 1.1 2013/11/04 16:41:16 joerg Exp $

--- resolv.h.orig	2013-11-04 15:25:15.000000000 +0000
+++ resolv.h
@@ -340,8 +340,7 @@ int			res_mkquery(struct dnsres *,
 void			res_send(struct dnsres *,
 			    const unsigned char *, int, unsigned char *, int,
 			    void (*)(int, struct res_search_state *),
-			    struct res_search_state *)
-			__attribute__((__bounded__(__string__,4,5)));
+			    struct res_search_state *);
 int			res_isourserver(struct dnsres *,
 			    const struct sockaddr_in *);
 int			res_nameinquery(const char *, int, int,
