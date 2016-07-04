$NetBSD: patch-.._.._ipxe_src_net_fcels.c,v 1.1.1.1 2016/07/04 07:30:50 jnemeth Exp $

--- ../../ipxe/src/net/fcels.c.orig	2015-01-25 20:27:57.000000000 +0000
+++ ../../ipxe/src/net/fcels.c
@@ -946,8 +946,11 @@ int fc_els_prli_tx ( struct fc_els *els,
 		     struct fc_els_prli_descriptor *descriptor, void *param ) {
 	struct {
 		struct fc_prli_frame frame;
-		uint8_t param[descriptor->param_len];
-	} __attribute__ (( packed )) prli;
+		uint8_t param[];
+	} __attribute__ (( packed )) *prli;
+	size_t plen = sizeof(*prli) + descriptor->param_len;
+	uint8_t prli_buf[plen];
+	prli = (void *)prli_buf;
 	struct fc_ulp *ulp;
 	int rc;
 
@@ -960,22 +963,22 @@ int fc_els_prli_tx ( struct fc_els *els,
 	}
 
 	/* Build frame for transmission */
-	memset ( &prli, 0, sizeof ( prli ) );
-	prli.frame.command = fc_els_tx_command ( els, FC_ELS_PRLI );
-	prli.frame.page_len =
-		( sizeof ( prli.frame.page ) + sizeof ( prli.param ) );
-	prli.frame.len = htons ( sizeof ( prli ) );
-	prli.frame.page.type = descriptor->type;
+	memset ( prli, 0, plen );
+	prli->frame.command = fc_els_tx_command ( els, FC_ELS_PRLI );
+	prli->frame.page_len =
+		( sizeof ( prli->frame.page ) + descriptor->param_len );
+	prli->frame.len = htons ( plen );
+	prli->frame.page.type = descriptor->type;
 	if ( fc_els_is_request ( els ) ) {
-		prli.frame.page.flags |= htons ( FC_PRLI_ESTABLISH );
+		prli->frame.page.flags |= htons ( FC_PRLI_ESTABLISH );
 	} else if ( fc_link_ok ( &ulp->link ) ) {
-		prli.frame.page.flags |= htons ( FC_PRLI_ESTABLISH |
+		prli->frame.page.flags |= htons ( FC_PRLI_ESTABLISH |
 						    FC_PRLI_RESPONSE_SUCCESS );
 	}
-	memcpy ( &prli.param, param, sizeof ( prli.param ) );
+	memcpy ( &prli->param, param, descriptor->param_len );
 
 	/* Transmit frame */
-	if ( ( rc = fc_els_tx ( els, &prli, sizeof ( prli ) ) ) != 0 )
+	if ( ( rc = fc_els_tx ( els, prli, plen ) ) != 0 )
 		goto err_tx;
 
 	/* Drop temporary reference to ULP */
@@ -1003,13 +1006,14 @@ int fc_els_prli_rx ( struct fc_els *els,
 		     void *data, size_t len ) {
 	struct {
 		struct fc_prli_frame frame;
-		uint8_t param[descriptor->param_len];
+		uint8_t param[];
 	} __attribute__ (( packed )) *prli = data;
+	size_t plen = sizeof(*prli) + descriptor->param_len;
 	struct fc_ulp *ulp;
 	int rc;
 
 	/* Sanity check */
-	if ( len < sizeof ( *prli ) ) {
+	if ( len < plen ) {
 		DBGC ( els, FCELS_FMT " received underlength frame:\n",
 		       FCELS_ARGS ( els ) );
 		DBGC_HDA ( els, 0, data, len );
@@ -1018,7 +1022,7 @@ int fc_els_prli_rx ( struct fc_els *els,
 	}
 
 	DBGC ( els, FCELS_FMT " has parameters:\n", FCELS_ARGS ( els ) );
-	DBGC_HDA ( els, 0, prli->param, sizeof ( prli->param ) );
+	DBGC_HDA ( els, 0, prli->param, descriptor->param_len );
 
 	/* Get ULP */
 	ulp = fc_ulp_get_port_id_type ( els->port, &els->peer_port_id,
@@ -1039,7 +1043,7 @@ int fc_els_prli_rx ( struct fc_els *els,
 	/* Log in ULP, if applicable */
 	if ( prli->frame.page.flags & htons ( FC_PRLI_ESTABLISH ) ) {
 		if ( ( rc = fc_ulp_login ( ulp, prli->param,
-					   sizeof ( prli->param ),
+					   descriptor->param_len,
 					   fc_els_is_request ( els ) ) ) != 0 ){
 			DBGC ( els, FCELS_FMT " could not log in ULP: %s\n",
 			       FCELS_ARGS ( els ), strerror ( rc ) );
@@ -1089,15 +1093,16 @@ int fc_els_prli_detect ( struct fc_els *
 			 const void *data, size_t len ) {
 	const struct {
 		struct fc_prli_frame frame;
-		uint8_t param[descriptor->param_len];
+		uint8_t param[];
 	} __attribute__ (( packed )) *prli = data;
+	size_t plen = sizeof(*prli) + descriptor->param_len;
 
 	/* Check for PRLI */
 	if ( prli->frame.command != FC_ELS_PRLI )
 		return -EINVAL;
 
 	/* Check for sufficient length to contain service parameter page */
-	if ( len < sizeof ( *prli ) )
+	if ( len < plen )
 		return -EINVAL;
 
 	/* Check for upper-layer protocol type */
@@ -1252,15 +1257,16 @@ static int fc_els_echo_rx_request ( stru
 				    size_t len ) {
 	struct {
 		struct fc_echo_frame_header echo;
-		char payload[ len - sizeof ( struct fc_echo_frame_header ) ];
+		char payload[];
 	} *echo = data;
+	size_t plen = suzeif(*echo) + len - sizeof ( struct fc_echo_frame_header );
 	int rc;
 
 	DBGC ( els, FCELS_FMT "\n", FCELS_ARGS ( els ) );
 
 	/* Transmit response */
 	echo->echo.command = FC_ELS_LS_ACC;
-	if ( ( rc = fc_els_tx ( els, echo, sizeof ( *echo ) ) ) != 0 )
+	if ( ( rc = fc_els_tx ( els, echo, plen ) ) != 0 )
 		return rc;
 
 	/* Nothing to do */
