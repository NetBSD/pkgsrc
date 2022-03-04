$NetBSD: patch-main_bridge__channel.c,v 1.2 2022/03/04 12:22:31 ryoon Exp $

* Fix segfault under NetBSD/aarch64 9.99.80.

--- main/bridge_channel.c.orig	2022-02-10 11:53:37.000000000 +0000
+++ main/bridge_channel.c
@@ -59,6 +59,13 @@
 #include "asterisk/message.h"
 #include "asterisk/core_local.h"
 
+/* XXX, pthread_equal() is misused to compare non-valid thread pointers */
+static int
+pt_pthread_equal(pthread_t t1, pthread_t t2)
+{
+	return t1 == t2;
+}
+
 /*!
  * \brief Used to queue an action frame onto a bridge channel and write an action frame into a bridge.
  * \since 12.0.0
@@ -259,7 +266,7 @@ int ast_bridge_channel_notify_talking(st
  */
 static void bridge_channel_poke(struct ast_bridge_channel *bridge_channel)
 {
-	if (!pthread_equal(pthread_self(), bridge_channel->thread)) {
+	if (!pt_pthread_equal(pthread_self(), bridge_channel->thread)) {
 		/* Wake up the bridge channel thread. */
 		ast_queue_frame(bridge_channel->chan, &ast_null_frame);
 	}
@@ -936,7 +943,7 @@ static int bridge_channel_queue_action_d
 	};
 
 	/* Make sure we don't end up trying to wait on ourself to deliver the frame */
-	ast_assert(!pthread_equal(pthread_self(), bridge_channel->thread));
+	ast_assert(!pt_pthread_equal(pthread_self(), bridge_channel->thread));
 
 	sync_payload = ast_alloca(sync_payload_len);
 	sync_payload->id = ast_atomic_fetchadd_int(&sync_ids, +1);
