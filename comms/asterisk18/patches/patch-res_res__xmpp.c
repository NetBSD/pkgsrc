$NetBSD: patch-res_res__xmpp.c,v 1.3 2021/06/27 21:39:27 jnemeth Exp $

--- res/res_xmpp.c.orig	2021-06-24 12:50:57.000000000 +0000
+++ res/res_xmpp.c
@@ -62,6 +62,13 @@
 #include "asterisk/config_options.h"
 #include "asterisk/json.h"
 
+/* XXX, pthread_equal() is misused to compare non-valid thread pointers */
+static int
+pt_pthread_equal(pthread_t t1, pthread_t t2)
+{
+	return t1 == t2;
+}
+
 /*** DOCUMENTATION
 	<application name="JabberSend" language="en_US" module="res_xmpp">
 		<synopsis>
@@ -3527,7 +3534,7 @@ static int xmpp_action_hook(void *data, 
 
 int ast_xmpp_client_disconnect(struct ast_xmpp_client *client)
 {
-	if ((client->thread != AST_PTHREADT_NULL) && !pthread_equal(pthread_self(), client->thread)) {
+	if ((client->thread != AST_PTHREADT_NULL) && !pt_pthread_equal(pthread_self(), client->thread)) {
 		xmpp_client_change_state(client, XMPP_STATE_DISCONNECTING);
 		pthread_cancel(client->thread);
 		pthread_join(client->thread, NULL);
@@ -3669,7 +3676,7 @@ static int xmpp_client_receive(struct as
 			/* if we stumble on the ending tag character,
 			   we skip any whitespace that follows it*/
 			if (c == '>') {
-				while (isspace(buf[pos+1])) {
+				while (isspace((unsigned char)buf[pos+1])) {
 					pos++;
 				}
 			}
