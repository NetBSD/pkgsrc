$NetBSD: patch-src_tX__midiin.cc,v 1.1 2012/07/01 09:42:20 sbd Exp $

--- src/tX_midiin.cc.orig	2003-08-21 22:41:50.000000000 +0000
+++ src/tX_midiin.cc
@@ -447,7 +447,7 @@ gboolean tX_midiin::midi_learn_destroy(G
 
 void tX_midiin::store_connections(FILE *rc, char *indent) 
 {
-	gzFile *rz=NULL;
+	gzFile rz=NULL;
 	
 	tX_store("%s<midi_connections>\n", indent);
 	strcat(indent, "\t");
