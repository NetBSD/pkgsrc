$NetBSD: patch-src_marclib.hxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - string constants are const char *

--- src/marclib.hxx~	1998-12-10 05:33:52.000000000 +0000
+++ src/marclib.hxx
@@ -59,9 +59,9 @@ extern "C" {
   void           codeconvert(char *string);
   char           charconvert(char c);
   int            subfcopy(char *To, char *From,int flag);
-  int            tagcmp(char *pattag, char *comptag);
+  int            tagcmp(const char *pattag, const char *comptag);
   MARC_FIELD    *GetField(MARC_REC *rec,MARC_FIELD *startf,
-		       char *buffer,char *tag);
+		       char *buffer,const char *tag);
   MARC_SUBFIELD *GetSubf(MARC_FIELD *f, char *buffer, char code);
   char          *normalize(char *in, char *out);
 /*
