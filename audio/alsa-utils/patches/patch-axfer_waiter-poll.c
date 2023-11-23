$NetBSD: patch-axfer_waiter-poll.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- axfer/waiter-poll.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ axfer/waiter-poll.c
@@ -13,7 +13,7 @@
 #include <errno.h>
 #include <poll.h>
 
-static int poll_prepare(struct waiter_context *)
+static int poll_prepare(struct waiter_context *waiter ATTRIBUTE_UNUSED)
 {
 	// Nothing to do because an instance of waiter has required data.
 	return 0;
@@ -30,7 +30,7 @@ static int poll_wait_event(struct waiter
 	return err;
 }
 
-static void poll_release(struct waiter_context *)
+static void poll_release(struct waiter_context *waiter ATTRIBUTE_UNUSED)
 {
 	// Nothing to do because an instance of waiter has required data.
 	return;
