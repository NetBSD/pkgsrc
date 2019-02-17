$NetBSD: patch-pdftexdir_pdftosrc-newpoppler.cc,v 1.4 2019/02/17 11:44:38 tnn Exp $

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
@@ -109,7 +109,7 @@ int main(int argc, char *argv[])
             fprintf(stderr, "No SourceName found\n");
             exit(1);
         }
-        outname = srcName.getString()->getCString();
+        outname = srcName.getString()->c_str();
         // We cannot free srcName, as objname shares its string.
         // srcName.free();
     } else if (objnum > 0) {
@@ -118,7 +118,7 @@ int main(int argc, char *argv[])
             fprintf(stderr, "Not a Stream object\n");
             exit(1);
         }
-        sprintf(buf, "%s", fileName->getCString());
+        sprintf(buf, "%s", fileName->c_str());
         if ((p = strrchr(buf, '.')) == 0)
             p = strchr(buf, 0);
         if (objgen == 0)
@@ -128,7 +128,7 @@ int main(int argc, char *argv[])
         outname = buf;
     } else {                    // objnum < 0 means we are extracting the XRef table
         extract_xref_table = true;
-        sprintf(buf, "%s", fileName->getCString());
+        sprintf(buf, "%s", fileName->c_str());
         if ((p = strrchr(buf, '.')) == 0)
             p = strchr(buf, 0);
         sprintf(p, ".xref");
@@ -161,7 +161,7 @@ int main(int argc, char *argv[])
                 Object objStr, obj1, obj2;
                 int nObjects, first, n;
                 int localOffset = 0;
-                Guint firstOffset;
+                unsigned int firstOffset;
 
                 objStr = xref->fetch(e->offset, 0);
                 assert(objStr.isStream());
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
