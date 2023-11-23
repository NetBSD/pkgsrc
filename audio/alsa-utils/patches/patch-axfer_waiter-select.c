$NetBSD: patch-axfer_waiter-select.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- axfer/waiter-select.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ axfer/waiter-select.c
@@ -34,7 +34,7 @@ struct select_state {
 	fd_set rfds_ex;
 };
 
-static int select_prepare(struct waiter_context *)
+static int select_prepare(struct waiter_context *waiter ATTRIBUTE_UNUSED)
 {
 	return 0;
 }
@@ -94,7 +94,7 @@ static int select_wait_event(struct wait
 	return err;
 }
 
-static void select_release(struct waiter_context *)
+static void select_release(struct waiter_context *waiter ATTRIBUTE_UNUSED)
 {
 	return;
 }
