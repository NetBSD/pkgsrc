$NetBSD: patch-src_config.c,v 1.1 2026/05/14 13:15:14 ktnb Exp $

Avoid segfault when parsing configuration file under NetBSD.

--- src/config.c.orig	2026-05-13 18:02:57.689819229 +0000
+++ src/config.c
@@ -433,7 +433,7 @@ load_config( const char *where )
 load_config( const char *where )
 {
 	conffile_t cfile;
-	store_conf_t *store, **storeapp = &stores;
+	store_conf_t *store = NULL, **storeapp = &stores;
 	channel_conf_t *channel, **channelapp = &channels;
 	group_conf_t *group, **groupapp = &groups;
 	string_list_t *chanlist, **chanlistapp;
