$NetBSD: patch-src_marclib.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - string constants are const char *

Also, use isdigit() correctly.

--- src/marclib.cxx~	1998-05-12 16:49:11.000000000 +0000
+++ src/marclib.cxx
@@ -458,13 +458,13 @@ int subfcopy(char *To, char *From,int fl
 /*          returns -1 for no match and 0 for match                 */
 /********************************************************************/
 
-int tagcmp(char *pattag, char *comptag)
+int tagcmp(const char *pattag, const char *comptag)
 {
   int i;
   for (i = 0; i < 3; i++) {
     if (pattag[i] == 'x' || pattag[i] == 'X')
       continue;
-    if (isdigit(pattag[i]) && pattag[i] == comptag[i])
+    if (isdigit((unsigned char)pattag[i]) && pattag[i] == comptag[i])
       continue;
     else
       return(-1);
@@ -482,7 +482,7 @@ int tagcmp(char *pattag, char *comptag)
 /*            field. Startf lets it start from later in a field list.*/
 /*            Permits "wildcard" comparisons using tagcmp            */
 /*********************************************************************/
-MARC_FIELD *GetField(MARC_REC *rec,MARC_FIELD *startf,char *buffer,char *tag)
+MARC_FIELD *GetField(MARC_REC *rec,MARC_FIELD *startf,char *buffer,const char *tag)
 {
   MARC_FIELD *f;
    
