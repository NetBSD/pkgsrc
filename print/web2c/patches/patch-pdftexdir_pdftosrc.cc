$NetBSD: patch-pdftexdir_pdftosrc.cc,v 1.1 2017/09/07 14:15:52 tnn Exp $

Try to adapt to new poppler-0.59 Object API.

--- pdftexdir/pdftosrc.cc.orig	2016-11-25 18:09:21.000000000 +0000
+++ pdftexdir/pdftosrc.cc
@@ -86,22 +86,22 @@ int main(int argc, char *argv[])
             objgen = atoi(argv[3]);
     }
     xref = doc->getXRef();
-    catalogDict.initNull();
-    xref->getCatalog(&catalogDict);
+    catalogDict.setToNull();
+    catalogDict = xref->getCatalog();
     if (!catalogDict.isDict("Catalog")) {
         fprintf(stderr, "No Catalog found\n");
         exit(1);
     }
-    srcStream.initNull();
+    srcStream.setToNull();
     if (objnum == 0) {
-        catalogDict.dictLookup("SourceObject", &srcStream);
+        srcStream = catalogDict.dictLookup("SourceObject");
         static char const_SourceFile[] = "SourceFile";
         if (!srcStream.isStream(const_SourceFile)) {
             fprintf(stderr, "No SourceObject found\n");
             exit(1);
         }
-        srcName.initNull();
-        srcStream.getStream()->getDict()->lookup("SourceName", &srcName);
+        srcName.setToNull();
+        srcName = srcStream.getStream()->getDict()->lookup("SourceName");
         if (!srcName.isString()) {
             fprintf(stderr, "No SourceName found\n");
             exit(1);
@@ -110,7 +110,7 @@ int main(int argc, char *argv[])
         // We cannot free srcName, as objname shares its string.
         // srcName.free();
     } else if (objnum > 0) {
-        xref->fetch(objnum, objgen, &srcStream);
+        srcStream = xref->fetch(objnum, objgen);
         if (!srcStream.isStream()) {
             fprintf(stderr, "Not a Stream object\n");
             exit(1);
@@ -159,29 +159,27 @@ int main(int argc, char *argv[])
                 int localOffset = 0;
                 Guint firstOffset;
 
-                assert(xref->fetch(e->offset, 0, &objStr)->isStream());
-                nObjects = objStr.streamGetDict()->lookup("N", &obj1)->getInt();
-                obj1.free();
-                first = objStr.streamGetDict()->lookup("First", &obj1)->getInt();
-                obj1.free();
+                assert(xref->fetch(e->offset, 0).isStream());
+                nObjects = objStr.streamGetDict()->lookup("N").getInt();
+                first = objStr.streamGetDict()->lookup("First").getInt();
                 firstOffset = objStr.getStream()->getBaseStream()->getStart() + first;
 
                 // parse the header: object numbers and offsets
                 objStr.streamReset();
-                obj1.initNull();
-                str = new EmbedStream(objStr.getStream(), &obj1, gTrue, first);
+                obj1.setToNull();
+                str = new EmbedStream(objStr.getStream(), Object(objNull), gTrue, first);
                 parser = new Parser(xref, new Lexer(xref, str), gFalse);
                 for (n = 0; n < nObjects; ++n) {
-                    parser->getObj(&obj1);
-                    parser->getObj(&obj2);
+                    obj1 = parser->getObj();
+                    obj2 = parser->getObj();
                     if (n == e->gen)
                         localOffset = obj2.getInt();
-                    obj1.free();
-                    obj2.free();
+                    obj1.setToNull();
+                    obj2.setToNull();
                 }
                 while (str->getChar() != EOF) ;
                 delete parser;
-                objStr.free();
+                objStr.setToNull();
 
                 fprintf(outfile, "%.10lu 00000 n\n",
                         (long unsigned)(firstOffset + localOffset));
@@ -192,7 +190,7 @@ int main(int argc, char *argv[])
         s->reset();
         while ((c = s->getChar()) != EOF)
             fputc(c, outfile);
-        srcStream.free();
+        srcStream.setToNull();
     }
     if (objnum == 0)
         fprintf(stderr, "Source file extracted to %s\n", outname);
@@ -201,7 +199,7 @@ int main(int argc, char *argv[])
     else
         fprintf(stderr, "Cross-reference table extracted to %s\n", outname);
     fclose(outfile);
-    catalogDict.free();
+    catalogDict.setToNull();
     delete doc;
     delete globalParams;
 }
