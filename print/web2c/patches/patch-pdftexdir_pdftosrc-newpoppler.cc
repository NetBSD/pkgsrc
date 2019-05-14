$NetBSD: patch-pdftexdir_pdftosrc-newpoppler.cc,v 1.6 2019/05/14 13:23:10 adam Exp $

Fix building.

--- pdftexdir/pdftosrc-newpoppler.cc.orig	2018-12-06 23:31:33.000000000 +0000
+++ pdftexdir/pdftosrc-newpoppler.cc
@@ -69,7 +69,7 @@ int main(int argc, char *argv[])
     Stream *s;
     Object srcStream, srcName, catalogDict;
     FILE *outfile;
-    char *outname;
+    const char *outname;
     int objnum = 0, objgen = 0;
     bool extract_xref_table = false;
     int c;
@@ -110,7 +110,7 @@ int main(int argc, char *argv[])
             fprintf(stderr, "No SourceName found\n");
             exit(1);
         }
-        outname = (char *)srcName.getString()->getCString();
+        outname = (char *)srcName.getString()->c_str();
         // We cannot free srcName, as objname shares its string.
         // srcName.free();
     } else if (objnum > 0) {
@@ -119,7 +119,7 @@ int main(int argc, char *argv[])
             fprintf(stderr, "Not a Stream object\n");
             exit(1);
         }
-        sprintf(buf, "%s", fileName->getCString());
+        sprintf(buf, "%s", fileName->c_str());
         if ((p = strrchr(buf, '.')) == 0)
             p = strchr(buf, 0);
         if (objgen == 0)
@@ -129,7 +129,7 @@ int main(int argc, char *argv[])
         outname = buf;
     } else {                    // objnum < 0 means we are extracting the XRef table
         extract_xref_table = true;
-        sprintf(buf, "%s", fileName->getCString());
+        sprintf(buf, "%s", fileName->c_str());
         if ((p = strrchr(buf, '.')) == 0)
             p = strchr(buf, 0);
         sprintf(p, ".xref");
@@ -157,12 +157,11 @@ int main(int argc, char *argv[])
                         (e->type == xrefEntryFree ? "f" : "n"));
             else {              // e->offset is the object number of the object stream
                 Stream *str;
-                Lexer *lexer;
                 Parser *parser;
                 Object objStr, obj1, obj2;
                 int nObjects, first, n;
                 int localOffset = 0;
-                Guint firstOffset;
+                unsigned int firstOffset;
 
                 objStr = xref->fetch(e->offset, 0);
                 assert(objStr.isStream());
@@ -174,9 +173,8 @@ int main(int argc, char *argv[])
 
                 // parse the header: object numbers and offsets
                 objStr.streamReset();
-                str = new EmbedStream(objStr.getStream(), Object(objNull), gTrue, first);
-                lexer = new Lexer(xref, str);
-                parser = new Parser(xref, lexer, gFalse);
+                str = new EmbedStream(objStr.getStream(), Object(objNull), true, first);
+                parser = new Parser(xref, str, false);
                 for (n = 0; n < nObjects; ++n) {
                     obj1 = parser->getObj();
                     obj2 = parser->getObj();
