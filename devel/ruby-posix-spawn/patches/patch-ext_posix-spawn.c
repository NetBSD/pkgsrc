$NetBSD: patch-ext_posix-spawn.c,v 1.1 2026/02/11 15:27:30 taca Exp $

Correct argument for rb_hash_each().

--- ext/posix-spawn.c.orig	2026-02-11 15:12:40.054932406 +0000
+++ ext/posix-spawn.c
@@ -196,9 +196,10 @@ posixspawn_file_actions_addopen(VALUE ke
  * if not.
  */
 static int
-posixspawn_file_actions_operations_iter(VALUE key, VALUE val, posix_spawn_file_actions_t *fops)
+posixspawn_file_actions_operations_iter(VALUE key, VALUE val, VALUE arg)
 {
 	int act;
+	posix_spawn_file_actions_t *fops = (posix_spawn_file_actions_t *)arg;
 
 	act = posixspawn_file_actions_addclose(key, val, fops);
 	if (act != ST_CONTINUE) return act;
