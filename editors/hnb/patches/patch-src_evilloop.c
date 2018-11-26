$NetBSD: patch-src_evilloop.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/evilloop.c.orig	2003-03-14 04:40:35.000000000 +0000
+++ src/evilloop.c
@@ -122,10 +122,10 @@
 
 int quit_hnb=0;
 
-static int cmd_quit(int argc,char **argv,void *data){
+static uint64_t cmd_quit(int argc,char **argv,void *data){
 	Node *pos=(Node *)data;
 	quit_hnb=1;
-	return (int)pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
