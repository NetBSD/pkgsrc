$NetBSD: patch-json__tokener.c,v 1.1 2014/04/20 02:29:49 ryoon Exp $

https://github.com/json-c/json-c/pull/132

--- json_tokener.c.orig	2014-04-11 00:41:08.000000000 +0000
+++ json_tokener.c
@@ -352,12 +352,10 @@ struct json_object* json_tokener_parse_e
 
     case json_tokener_state_inf: /* aka starts with 'i' */
       {
-	int size;
 	int size_inf;
 	int is_negative = 0;
 
 	printbuf_memappend_fast(tok->pb, &c, 1);
-	size = json_min(tok->st_pos+1, json_null_str_len);
 	size_inf = json_min(tok->st_pos+1, json_inf_str_len);
 	char *infbuf = tok->pb->buf;
 	if (*infbuf == '-')
