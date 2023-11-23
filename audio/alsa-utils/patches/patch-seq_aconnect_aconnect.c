$NetBSD: patch-seq_aconnect_aconnect.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- seq/aconnect/aconnect.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ seq/aconnect/aconnect.c
@@ -193,7 +193,8 @@ static void do_search_port(snd_seq_t *se
 }
 
 
-static void print_port(snd_seq_t *, snd_seq_client_info_t *cinfo,
+static void print_port(snd_seq_t *seq ATTRIBUTE_UNUSED,
+		       snd_seq_client_info_t *cinfo,
 		       snd_seq_port_info_t *pinfo, int count)
 {
 	if (! count) {
@@ -247,8 +248,10 @@ static void print_port_and_subs(snd_seq_
 /*
  * remove all (exported) connections
  */
-static void remove_connection(snd_seq_t *seq, snd_seq_client_info_t *,
-			      snd_seq_port_info_t *pinfo, int)
+static void remove_connection(snd_seq_t *seq,
+			      snd_seq_client_info_t *info ATTRIBUTE_UNUSED,
+			      snd_seq_port_info_t *pinfo,
+			      int count ATTRIBUTE_UNUSED)
 {
 	snd_seq_query_subscribe_t *query;
 	snd_seq_port_info_t *port;
