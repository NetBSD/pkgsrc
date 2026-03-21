$NetBSD: patch-src_upclient.c,v 1.1 2026/03/21 10:38:34 nia Exp $

Fix implicit function declarations.

--- src/upclient.c.orig	2026-03-21 10:22:14.803978262 +0000
+++ src/upclient.c
@@ -98,6 +98,8 @@
 int past_idle_times[NUM_IDLE_ELEMENTS] = { -1 };
 #endif
 
+int read_config(void);
+
 
 /**
  * @desc	Actual function that makes the connection to the
