$NetBSD: patch-src_drv__imap.c,v 1.2 2021/02/17 15:10:11 ryoon Exp $

* Fix some runtime errors.
  From upstream Git: 9e3041de9367113f3b2d7d7543d2eae4c78e2c67 to 95a83c8220861185906df5b38eed589984847bfb

--- src/drv_imap.c
+++ src/drv_imap.c
@@ -924,6 +924,7 @@ parse_imap_list( imap_store_t *ctx, char **sp, parse_list_state_t *sts )
 	}
   bail:
 	free_list( sts->head );
+	sts->level = 0;
 	return LIST_BAD;
 }
 
@@ -1181,7 +1182,8 @@ parse_fetch_rsp( imap_store_t *ctx, list_t *list, char *s ATTR_UNUSED )
 		for (cmdp = ctx->in_progress; cmdp; cmdp = cmdp->next)
 			if (cmdp->param.uid == uid)
 				goto gotuid;
-		goto badrsp;
+		error( "IMAP error: unexpected FETCH response with BODY (UID %u)\n", uid );
+		return LIST_BAD;
 	  gotuid:
 		msgdata = ((imap_cmd_fetch_msg_t *)cmdp)->msg_data;
 		msgdata->data = body->val;
@@ -1208,9 +1210,8 @@ parse_fetch_rsp( imap_store_t *ctx, list_t *list, char *s ATTR_UNUSED )
 			memcpy( cur->tuid, tuid, TUIDL );
 		status &= ~(M_FLAGS | M_RECENT | M_SIZE | M_HEADER);
 	} else {
-	  badrsp:
-		error( "IMAP error: unexpected FETCH response (UID %u)\n", uid );
-		return LIST_BAD;
+		// These may come in as a result of STORE FLAGS despite .SILENT.
+		status &= ~(M_FLAGS | M_RECENT);
 	}
 
 	if (status) {
@@ -1252,48 +1253,53 @@ parse_response_code( imap_store_t *ctx, imap_cmd_t *cmd, char *s )
 	if (!s || *s != '[')
 		return RESP_OK;		/* no response code */
 	s++;
-	if (!(p = strchr( s, ']' ))) {
-	  bad_resp:
+	if (!(arg = next_arg( &s ))) {
 		error( "IMAP error: malformed response code\n" );
 		return RESP_CANCEL;
 	}
-	*p++ = 0;
-	if (!(arg = next_arg( &s )))
-		goto bad_resp;
 	if (!strcmp( "UIDVALIDITY", arg )) {
 		if (!(arg = next_arg( &s )) ||
-		    (ctx->uidvalidity = strtoul( arg, &earg, 10 ), *earg))
+		    (ctx->uidvalidity = strtoul( arg, &earg, 10 ), *earg != ']'))
 		{
 			error( "IMAP error: malformed UIDVALIDITY status\n" );
 			return RESP_CANCEL;
 		}
 	} else if (!strcmp( "UIDNEXT", arg )) {
 		if (!(arg = next_arg( &s )) ||
-		    (ctx->uidnext = strtoul( arg, &earg, 10 ), *earg))
+		    (ctx->uidnext = strtoul( arg, &earg, 10 ), *earg != ']'))
 		{
 			error( "IMAP error: malformed UIDNEXT status\n" );
 			return RESP_CANCEL;
 		}
 	} else if (!strcmp( "CAPABILITY", arg )) {
+		if (!(p = strchr( s, ']' ))) {
+			error( "IMAP error: malformed CAPABILITY status\n" );
+			return RESP_CANCEL;
+		}
+		*p = 0;
 		parse_capability( ctx, s );
-	} else if (!strcmp( "ALERT", arg )) {
+	} else if (!strcmp( "ALERT]", arg )) {
 		/* RFC2060 says that these messages MUST be displayed
 		 * to the user
 		 */
-		for (; isspace( (uchar)*p ); p++);
-		error( "*** IMAP ALERT *** %s\n", p );
+		if (!s) {
+			error( "IMAP error: malformed ALERT status\n" );
+			return RESP_CANCEL;
+		}
+		for (; isspace( (uchar)*s ); s++);
+		error( "*** IMAP ALERT *** %s\n", s );
 	} else if (cmd && !strcmp( "APPENDUID", arg )) {
 		if (!(arg = next_arg( &s )) ||
 		    (ctx->uidvalidity = strtoul( arg, &earg, 10 ), *earg) ||
 		    !(arg = next_arg( &s )) ||
-		    (((imap_cmd_out_uid_t *)cmd)->out_uid = strtoul( arg, &earg, 10 ), *earg))
+		    (((imap_cmd_out_uid_t *)cmd)->out_uid = strtoul( arg, &earg, 10 ), *earg != ']'))
 		{
 			error( "IMAP error: malformed APPENDUID status\n" );
 			return RESP_CANCEL;
 		}
 	} else if (!strcmp( "PERMANENTFLAGS", arg )) {
 		parse_list_init( &ctx->parse_list_sts );
-		if (parse_imap_list( NULL, &s, &ctx->parse_list_sts ) != LIST_OK) {
+		if (parse_imap_list( NULL, &s, &ctx->parse_list_sts ) != LIST_OK || *s != ']') {
 			error( "IMAP error: malformed PERMANENTFLAGS status\n" );
 			return RESP_CANCEL;
 		}
