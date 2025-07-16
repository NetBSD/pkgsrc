$NetBSD: patch-examples_threads.c,v 1.1 2025/07/16 10:26:52 jperkin Exp $

Fix type.

--- examples/threads.c.orig	2025-07-16 10:22:46.962677731 +0000
+++ examples/threads.c
@@ -5,7 +5,7 @@
 /* our thread-specific data */
 typedef struct
 {
-  ClutterActor *stage;
+  ClutterStage *stage;
   ClutterActor *label;
   ClutterActor *progress;
   ClutterActor *rect;
