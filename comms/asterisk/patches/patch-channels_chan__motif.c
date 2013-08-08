$NetBSD: patch-channels_chan__motif.c,v 1.1 2013/08/08 00:45:10 jnemeth Exp $

--- channels/chan_motif.c.orig	2012-12-09 01:22:56.000000000 +0000
+++ channels/chan_motif.c
@@ -337,11 +337,14 @@ static struct jingle_endpoint_state *jin
 	return state;
 }
 
+RAII_DECL(struct jingle_config *, cfg, ao2_cleanup);
+RAII_DECL(struct jingle_endpoint *, endpoint, ao2_cleanup);
+
 /*! \brief State find/create function */
 static struct jingle_endpoint_state *jingle_endpoint_state_find_or_create(const char *category)
 {
-	RAII_VAR(struct jingle_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct jingle_endpoint *, endpoint, NULL, ao2_cleanup);
+	RAII_VAR(struct jingle_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct jingle_endpoint *, endpoint, NULL);
 
 	if (!cfg || !cfg->endpoints || !(endpoint = jingle_endpoint_find(cfg->endpoints, category))) {
 		return jingle_endpoint_state_create();
@@ -1729,8 +1732,8 @@ static int jingle_hangup(struct ast_chan
 /*! \brief Function called by core to create a new outgoing Jingle session */
 static struct ast_channel *jingle_request(const char *type, struct ast_format_cap *cap, const struct ast_channel *requestor, const char *data, int *cause)
 {
-	RAII_VAR(struct jingle_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct jingle_endpoint *, endpoint, NULL, ao2_cleanup);
+	RAII_VAR(struct jingle_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct jingle_endpoint *, endpoint, NULL);
 	char *dialed, target[200] = "";
 	struct ast_xmpp_buddy *buddy;
 	struct jingle_session *session;
