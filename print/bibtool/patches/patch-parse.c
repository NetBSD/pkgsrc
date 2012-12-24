$NetBSD: patch-parse.c,v 1.1 2012/12/24 01:50:58 dholland Exp $

Fix bug handling EOF, detected by gcc.

--- parse.c~	2004-02-08 09:41:45.000000000 +0000
+++ parse.c
@@ -533,13 +533,15 @@ static void parse_number()			   /*			   
 static int parse_string(quotep)			   /*			     */
   int   quotep;				   	   /*			     */
 { Uchar c;					   /*                        */
+  int   c1;					   /*                        */
   int   left;				   	   /*			     */
   int   start_flno = flno;			   /*                        */
 						   /*			     */
   left = 0;					   /*			     */
   if ( quotep ) (void)sbputchar('"',parse_sb);	   /*"			     */
   do						   /*			     */
-  { switch ( c=skip_nl() )			   /*			     */
+  { c=c1=skip_nl();				   /*                        */
+    switch ( c1 )				   /*			     */
     { case EOF:					   /*                        */
 	UnterminatedError("Unterminated double quote",
 			  start_flno);
