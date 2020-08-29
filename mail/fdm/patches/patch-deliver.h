$NetBSD: patch-deliver.h,v 1.1 2020/08/29 13:43:54 leot Exp $

Add support for OAUTHBEARER (OAuth 2.0 bearer tokens, as documented by
RFC 7628) for IMAP.

Patch shared upstream via:

 <https://github.com/nicm/fdm/pull/84>

--- deliver.h.orig	2019-02-12 22:08:26.000000000 +0000
+++ deliver.h
@@ -82,6 +82,7 @@ struct deliver_imap_data {
 	struct server	 server;
 	int		 nocrammd5;
 	int		 nologin;
+	int		 oauthbearer;
 	int		 starttls;
 
 	struct replstr	 folder;
