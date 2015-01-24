$NetBSD: patch-parse.c,v 1.2 2015/01/24 13:40:14 mef Exp $

Fix bug handling EOF, detected by gcc.

--- parse.c.orig	2014-01-14 04:16:16.000000000 +0900
+++ parse.c	2015-01-24 22:13:12.000000000 +0900
@@ -536,14 +536,16 @@ static void parse_number()			   /*			   
 static int parse_string(quotep)			   /*			     */
   int quotep;				   	   /*			     */
 { int c;					   /*                        */
+  int c1;
   int left;				   	   /*			     */
   int start_flno = flno;			   /*                        */
 						   /*			     */
   left = 0;					   /*			     */
   if ( quotep ) (void)sbputchar('"',parse_sb);	   /*"			     */
   do						   /*			     */
-  { switch ( c=skip_nl() )			   /*			     */
-    { case EOF:					   /*                        */
+  { c=c1=skip_nl();				   /*			     */
+    switch ( c1 )				   /*			     */
+    { case EOF:					   /*			     */
 	UnterminatedError("Unterminated double quote",/*                     */
 			  start_flno);		   /*                        */
 	return(FALSE);	   			   /*			     */
