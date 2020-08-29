$NetBSD: patch-fetch.h,v 1.1 2020/08/29 13:43:54 leot Exp $

Add support for OAUTHBEARER (OAuth 2.0 bearer tokens, as documented by
RFC 7628) for IMAP.

Patch shared upstream via:

 <https://github.com/nicm/fdm/pull/84>

--- fetch.h.orig	2019-02-12 22:08:26.000000000 +0000
+++ fetch.h
@@ -204,6 +204,7 @@ struct fetch_imap_data {
 	int		 starttls;
 	int		 nocrammd5;
 	int		 nologin;
+	int		 oauthbearer;
 
 	u_int		 folder;
 	struct strings	*folders;
@@ -252,6 +253,7 @@ struct fetch_imap_mail {
 #define IMAP_CAPA_STARTTLS 0x4
 #define IMAP_CAPA_NOSPACE 0x8
 #define IMAP_CAPA_GMEXT 0x10
+#define IMAP_CAPA_AUTH_OAUTHBEARER 0x20
 
 /* fetch-maildir.c */
 extern struct fetch	 fetch_maildir;
