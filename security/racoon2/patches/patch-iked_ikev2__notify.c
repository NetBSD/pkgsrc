$NetBSD: patch-iked_ikev2__notify.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Fix unused

--- iked/ikev2_notify.c.orig	2008-02-06 03:09:00.000000000 -0500
+++ iked/ikev2_notify.c	2018-05-28 20:05:41.431368140 -0400
@@ -281,12 +281,16 @@
 			     struct ikev2_child_param *child_param,
 			     int *http_cert_lookup_supported)
 {
-	struct ikev2_header *ikehdr;
 	struct ikev2payl_notify *notify;
+#ifdef notyet
+	struct ikev2_header *ikehdr;
 	uint32_t message_id;
+#endif
 
+#ifdef notyet
 	ikehdr = (struct ikev2_header *)msg->v;
 	message_id = get_uint32(&ikehdr->message_id);
+#endif
 	notify = (struct ikev2payl_notify *)payload;
 
 	switch (get_notify_type(notify)) {
