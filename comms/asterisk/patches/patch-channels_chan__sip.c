$NetBSD: patch-channels_chan__sip.c,v 1.2 2015/05/19 07:52:14 jnemeth Exp $

--- channels/chan_sip.c.orig	2015-03-19 09:39:28.000000000 +0000
+++ channels/chan_sip.c
@@ -17515,6 +17515,8 @@ static int get_rdnis(struct sip_pvt *p, 
 	return 0;
 }
 
+RAII_DECL(char *, tmpf, ast_free);
+
 /*!
  * \brief Find out who the call is for.
  *
@@ -17532,7 +17534,7 @@ static int get_rdnis(struct sip_pvt *p, 
 static enum sip_get_dest_result get_destination(struct sip_pvt *p, struct sip_request *oreq, int *cc_recall_core_id)
 {
 	char tmp[256] = "", *uri, *unused_password, *domain;
-	RAII_VAR(char *, tmpf, NULL, ast_free);
+	RAII_VAR(char *, tmpf, NULL);
 	char *from = NULL;
 	struct sip_request *req;
 	char *decoded_uri;
@@ -18405,6 +18407,8 @@ static enum check_auth_result check_peer
 	return res;
 }
 
+RAII_DECL(char *, ofbuf, ast_free); /* beware, everyone starts pointing to this */
+RAII_DECL(char *, namebuf, ast_free);
 
 /*! \brief  Check if matching user or peer is defined
  	Match user on From: user name and peer on IP/port
@@ -18416,8 +18420,8 @@ static enum check_auth_result check_user
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
@@ -19054,7 +19058,7 @@ static int manager_show_registry(struct 
 			"DomainPort: %d\r\n"
 			"Refresh: %d\r\n"
 			"State: %s\r\n"
-			"RegistrationTime: %ld\r\n"
+			"RegistrationTime: %jd\r\n"
 			"\r\n",
 			idtext,
 			iterator->hostname,
@@ -19064,7 +19068,7 @@ static int manager_show_registry(struct 
 			iterator->regdomainport ? iterator->regdomainport : STANDARD_SIP_PORT,
 			iterator->refresh,
 			regstate2str(iterator->regstate),
-			(long) iterator->regtime.tv_sec);
+			(intmax_t) iterator->regtime.tv_sec);
 		ASTOBJ_UNLOCK(iterator);
 		total++;
 	} while(0));
@@ -29112,8 +29116,8 @@ static int check_rtp_timeout(struct sip_
 					 */
 					return 0;
 				}
-				ast_log(LOG_NOTICE, "Disconnecting call '%s' for lack of RTP activity in %ld seconds\n",
-					ast_channel_name(dialog->owner), (long) (t - dialog->lastrtprx));
+				ast_log(LOG_NOTICE, "Disconnecting call '%s' for lack of RTP activity in %jd seconds\n",
+					ast_channel_name(dialog->owner), (intmax_t) (t - dialog->lastrtprx));
 				manager_event(EVENT_FLAG_CALL, "SessionTimeout", "Source: RTPTimeout\r\n"
 						"Channel: %s\r\nUniqueid: %s\r\n", ast_channel_name(dialog->owner), ast_channel_uniqueid(dialog->owner));
 				/* Issue a softhangup */
