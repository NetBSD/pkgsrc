$NetBSD: patch-res_res__xmpp.c,v 1.1 2021/02/11 11:54:13 ryoon Exp $

* Fix segfault under NetBSD/aarch64 9.99.80.

--- res/res_xmpp.c.orig	2021-01-21 16:28:04.000000000 +0000
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
@@ -3609,7 +3616,7 @@ static int xmpp_action_hook(void *data, 
 
 int ast_xmpp_client_disconnect(struct ast_xmpp_client *client)
 {
-	if ((client->thread != AST_PTHREADT_NULL) && !pthread_equal(pthread_self(), client->thread)) {
+	if ((client->thread != AST_PTHREADT_NULL) && !pt_pthread_equal(pthread_self(), client->thread)) {
 		xmpp_client_change_state(client, XMPP_STATE_DISCONNECTING);
 		pthread_cancel(client->thread);
 		pthread_join(client->thread, NULL);
