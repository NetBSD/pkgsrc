$NetBSD: patch-main.c,v 1.1 2012/12/24 01:50:57 dholland Exp $

Remove wrong casts.

--- main.c~	2004-02-08 09:41:38.000000000 +0000
+++ main.c
@@ -789,10 +789,10 @@ static int update_crossref(db,rec)		   /
 						   /*			     */
   t = *++hp; t++;				   /*			     */
   (void)sp_open(t);				   /* Try to extract	     */
-  if ( (s = SParseSymbol(&t)) == (Uchar)NULL )	   /*  the crossref as symbol*/
+  if ( (s = SParseSymbol(&t)) == NULL )		   /*  the crossref as symbol*/
   { return 0; }					   /*			     */
 						   /*			     */
-  if ( (s = db_new_key(db,s)) == (Uchar)NULL )	   /*			     */
+  if ( (s = db_new_key(db,s)) == NULL )		   /*			     */
   { ERROR2("Crossref not found: ",(char*)s);	   /*			     */
     return 0;					   /*			     */
   }						   /*			     */
