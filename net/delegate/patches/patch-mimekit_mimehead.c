$NetBSD: patch-mimekit_mimehead.c,v 1.1 2022/09/18 22:46:25 he Exp $

Follow up spreading of unsigned-ness.

--- ./mimekit/mimehead.c.orig	2009-01-13 02:14:09.000000000 +0000
+++ ./mimekit/mimehead.c
@@ -879,7 +879,7 @@ int MIME_headerEncodeX(MimeConv *Mcv,FIL
 static void DE_FPUTC1X(CHARx *CH,INOUT *Out)
 {	FILE *out;
 	int cset;
-	int ch;
+	unsigned int ch;
 
 	out = Out->out_file;
 	ch = CH->c_ch;
@@ -914,7 +914,8 @@ static void DE_FPUTC1(int ch,INOUT *io)
 }
 
 static void dumpDECODER(CHARx *CH,INOUT *io)
-{	int i,ch;
+{	int i;
+	unsigned int ch;
 	CStr(sym,16);
 
 	switch( ch = CH->c_ch ){
