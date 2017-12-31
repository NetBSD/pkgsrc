$NetBSD: patch-pdftexdir_pdftosrc.cc,v 1.3 2017/12/31 00:44:32 markd Exp $

Allow recent poppler - from ArchLinux

--- pdftexdir/pdftosrc.cc.orig	2016-11-25 18:09:21.000000000 +0000
+++ pdftexdir/pdftosrc.cc
@@ -86,22 +86,20 @@ int main(int argc, char *argv[])
             objgen = atoi(argv[3]);
     }
     xref = doc->getXRef();
-    catalogDict.initNull();
-    xref->getCatalog(&catalogDict);
+    catalogDict = xref->getCatalog();
     if (!catalogDict.isDict("Catalog")) {
         fprintf(stderr, "No Catalog found\n");
         exit(1);
     }
-    srcStream.initNull();
+    srcStream = Object(objNull);
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
+        srcName = srcStream.getStream()->getDict()->lookup("SourceName");
         if (!srcName.isString()) {
             fprintf(stderr, "No SourceName found\n");
             exit(1);
@@ -110,7 +108,7 @@ int main(int argc, char *argv[])
         // We cannot free srcName, as objname shares its string.
         // srcName.free();
     } else if (objnum > 0) {
-        xref->fetch(objnum, objgen, &srcStream);
+        srcStream = xref->fetch(objnum, objgen);
         if (!srcStream.isStream()) {
             fprintf(stderr, "Not a Stream object\n");
             exit(1);
@@ -159,29 +157,26 @@ int main(int argc, char *argv[])
                 int localOffset = 0;
                 Guint firstOffset;
 
-                assert(xref->fetch(e->offset, 0, &objStr)->isStream());
-                nObjects = objStr.streamGetDict()->lookup("N", &obj1)->getInt();
-                obj1.free();
-                first = objStr.streamGetDict()->lookup("First", &obj1)->getInt();
-                obj1.free();
+                objStr = xref->fetch(e->offset, 0);
+                assert(objStr.isStream());
+                obj1 = objStr.streamGetDict()->lookup("N");
+                nObjects = obj1.getInt();
+                obj1 = objStr.streamGetDict()->lookup("First");
+                first = obj1.getInt();
                 firstOffset = objStr.getStream()->getBaseStream()->getStart() + first;
 
                 // parse the header: object numbers and offsets
                 objStr.streamReset();
-                obj1.initNull();
-                str = new EmbedStream(objStr.getStream(), &obj1, gTrue, first);
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
                 }
                 while (str->getChar() != EOF) ;
                 delete parser;
-                objStr.free();
 
                 fprintf(outfile, "%.10lu 00000 n\n",
                         (long unsigned)(firstOffset + localOffset));
@@ -192,7 +187,6 @@ int main(int argc, char *argv[])
         s->reset();
         while ((c = s->getChar()) != EOF)
             fputc(c, outfile);
-        srcStream.free();
     }
     if (objnum == 0)
         fprintf(stderr, "Source file extracted to %s\n", outname);
@@ -201,7 +195,6 @@ int main(int argc, char *argv[])
     else
         fprintf(stderr, "Cross-reference table extracted to %s\n", outname);
     fclose(outfile);
-    catalogDict.free();
     delete doc;
     delete globalParams;
 }
