$NetBSD: patch-src_drv__imap.c,v 1.4 2023/05/13 08:49:27 ryoon Exp $

Fix non-critical runtime error with OpenSSL 3.
From: Upstream b6c36624f04cd388873785c0631df3f2f9ac4bf0

--- src/drv_imap.c.orig	2021-12-03 10:56:16.000000000 +0000
+++ src/drv_imap.c
@@ -1620,6 +1620,7 @@ imap_socket_read( void *aux )
 					error( "IMAP error: unexpected BYE response: %s\n", cmd );
 					/* We just wait for the server to close the connection now. */
 					ctx->expectEOF = 1;
+					socket_expect_eof( &ctx->conn );
 				} else {
 					/* We still need to wait for the LOGOUT's tagged OK. */
 				}
@@ -1882,10 +1883,12 @@ static void
 imap_cleanup_p2( imap_store_t *ctx,
                  imap_cmd_t *cmd ATTR_UNUSED, int response )
 {
-	if (response == RESP_NO)
+	if (response == RESP_NO) {
 		imap_cancel_store( &ctx->gen );
-	else if (response == RESP_OK)
+	} else if (response == RESP_OK) {
 		ctx->expectEOF = 1;
+		socket_expect_eof( &ctx->conn );
+	}
 }
 
 /******************* imap_open_store *******************/
