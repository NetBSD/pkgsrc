$NetBSD: patch-shared_config.c,v 1.1 2020/03/19 11:30:26 nia Exp $

Bug-Debian: https://bugs.debian.org/828512
Description: Support OpenSSL 1.1 API changes
 SSL_CTX_set_tmp_rsa_callback() (used for export-weakened keys) no longer does anything.

--- shared/config.c.orig	2012-06-30 14:30:08.000000000 +0000
+++ shared/config.c
@@ -455,9 +455,9 @@ static struct {
     "draft_att_total_max", config_number, OFFSET(draft_att_total_max)}
     , {
     "dualuse", config_bool, OFFSET(dualuse)}
-    , {
+    , /*{
     "egd_socket", config_path, OFFSET(egd_socket)}
-    , {
+    , */{
     "expunge_on_exit", config_bool, OFFSET(expunge_on_exit)}
     , {
     "fatal_dump_core", config_bool, OFFSET(fatal_dump_core)}
