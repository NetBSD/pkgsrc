$NetBSD: patch-pdftexdir_pdftosrc-newpoppler.cc,v 1.2 2018/12/04 13:01:44 ryoon Exp $

--- pdftexdir/pdftosrc-newpoppler.cc.orig	2017-10-17 21:52:13.000000000 +0000
+++ pdftexdir/pdftosrc-newpoppler.cc
@@ -68,7 +68,7 @@ int main(int argc, char *argv[])
     Stream *s;
     Object srcStream, srcName, catalogDict;
     FILE *outfile;
-    char *outname;
+    const char *outname;
     int objnum = 0, objgen = 0;
     bool extract_xref_table = false;
     int c;
@@ -173,9 +173,9 @@ int main(int argc, char *argv[])
 
                 // parse the header: object numbers and offsets
                 objStr.streamReset();
-                str = new EmbedStream(objStr.getStream(), Object(objNull), gTrue, first);
+                str = new EmbedStream(objStr.getStream(), Object(objNull), true, first);
                 lexer = new Lexer(xref, str);
-                parser = new Parser(xref, lexer, gFalse);
+                parser = new Parser(xref, lexer, false);
                 for (n = 0; n < nObjects; ++n) {
                     obj1 = parser->getObj();
                     obj2 = parser->getObj();
