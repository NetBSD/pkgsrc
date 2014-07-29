$NetBSD: patch-channels_chan__sip.c,v 1.1 2014/07/29 04:20:55 jnemeth Exp $

--- channels/chan_sip.c.orig	2014-06-30 19:42:18.000000000 +0000
+++ channels/chan_sip.c
@@ -17537,6 +17537,8 @@ static int get_rdnis(struct sip_pvt *p, 
 	return 0;
 }
 
+RAII_DECL(char *, tmpf, ast_free);
+
 /*!
  * \brief Find out who the call is for.
  *
@@ -17554,7 +17556,7 @@ static int get_rdnis(struct sip_pvt *p, 
 static enum sip_get_dest_result get_destination(struct sip_pvt *p, struct sip_request *oreq, int *cc_recall_core_id)
 {
 	char tmp[256] = "", *uri, *unused_password, *domain;
-	RAII_VAR(char *, tmpf, NULL, ast_free);
+	RAII_VAR(char *, tmpf, NULL);
 	char *from = NULL;
 	struct sip_request *req;
 	char *decoded_uri;
@@ -18426,6 +18428,8 @@ static enum check_auth_result check_peer
 	return res;
 }
 
+RAII_DECL(char *, ofbuf, ast_free); /* beware, everyone starts pointing to this */
+RAII_DECL(char *, namebuf, ast_free);
 
 /*! \brief  Check if matching user or peer is defined
  	Match user on From: user name and peer on IP/port
@@ -18437,8 +18441,8 @@ static enum check_auth_result check_user
 					      struct ast_sockaddr *addr, struct sip_peer **authpeer)
 {
 	char *of, *name, *unused_password, *domain;
-	RAII_VAR(char *, ofbuf, NULL, ast_free); /* beware, everyone starts pointing to this */
-	RAII_VAR(char *, namebuf, NULL, ast_free);
+	RAII_VAR(char *, ofbuf, NULL); /* beware, everyone starts pointing to this */
+	RAII_VAR(char *, namebuf, NULL);
 	enum check_auth_result res = AUTH_DONT_KNOW;
 	char calleridname[256];
 	char *uri2 = ast_strdupa(uri);
