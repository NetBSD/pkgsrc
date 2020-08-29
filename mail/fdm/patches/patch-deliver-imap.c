$NetBSD: patch-deliver-imap.c,v 1.1 2020/08/29 13:43:54 leot Exp $

Add support for OAUTHBEARER (OAuth 2.0 bearer tokens, as documented by
RFC 7628) for IMAP.

Patch shared upstream via:

 <https://github.com/nicm/fdm/pull/84>

--- deliver-imap.c.orig	2019-02-12 22:08:26.000000000 +0000
+++ deliver-imap.c
@@ -197,6 +197,7 @@ deliver_imap_deliver(struct deliver_ctx 
 	fdata.pass = data->pass;
 	fdata.nocrammd5 = data->nocrammd5;
 	fdata.nologin = data->nologin;
+	fdata.oauthbearer = data->oauthbearer;
 	memcpy(&fdata.server, &data->server, sizeof fdata.server);
 	fdata.io = io;
 	fdata.only = FETCH_ONLY_ALL;
