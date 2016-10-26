$NetBSD: patch-res_res__fax.c,v 1.1 2016/10/26 05:53:37 jnemeth Exp $

--- res/res_fax.c.orig	2016-10-25 18:53:17.000000000 +0000
+++ res/res_fax.c
@@ -2982,6 +2982,10 @@ static void fax_gateway_framehook_destro
 	ao2_ref(gateway, -1);
 }
 
+RAII_DECL(struct ast_fax_session_details *, details, ao2_cleanup);
+RAII_DECL(struct ast_channel *, peer, ao2_cleanup);
+RAII_DECL(struct ast_channel *, chan_ref, ao2_cleanup);
+
 /*!
  * \brief T.30<->T.38 gateway framehook.
  *
@@ -3002,9 +3006,9 @@ static struct ast_frame *fax_gateway_fra
 {
 	struct fax_gateway *gateway = data;
 	struct ast_channel *active;
-	RAII_VAR(struct ast_fax_session_details *, details, NULL, ao2_cleanup);
-	RAII_VAR(struct ast_channel *, peer, NULL, ao2_cleanup);
-	RAII_VAR(struct ast_channel *, chan_ref, chan, ao2_cleanup);
+	RAII_VAR(struct ast_fax_session_details *, details, NULL);
+	RAII_VAR(struct ast_channel *, peer, NULL);
+	RAII_VAR(struct ast_channel *, chan_ref, chan);
 
 	/* Ref bump channel for when we have to unlock it */
 	ao2_ref(chan_ref, 1);
@@ -3347,7 +3351,7 @@ static struct ast_frame *fax_detect_fram
 	struct ast_fax_session_details *details;
 	struct ast_control_t38_parameters *control_params;
 	struct ast_channel *peer;
-	RAII_VAR(struct ast_channel *, chan_ref, chan, ao2_cleanup);
+	RAII_VAR(struct ast_channel *, chan_ref, chan);
 	int result = 0;
 
 	/* Ref bump the channel for when we have to unlock it */
