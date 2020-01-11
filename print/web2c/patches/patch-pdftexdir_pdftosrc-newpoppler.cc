$NetBSD: patch-pdftexdir_pdftosrc-newpoppler.cc,v 1.7 2020/01/11 00:31:05 ryoon Exp $

Fix building.

--- pdftexdir/pdftosrc-newpoppler.cc.orig	2018-12-06 23:31:33.000000000 +0000
+++ pdftexdir/pdftosrc-newpoppler.cc
@@ -20,8 +20,7 @@ with this program.  If not, see <http://
 /*
 This is based on the patch texlive-poppler-0.59.patch <2017-09-19> at
 https://git.archlinux.org/svntogit/packages.git/plain/texlive-bin/trunk
-by Arch Linux. The poppler should be 0.59.0 or newer versions.
-It is tested upto the poppler 0.70.1.
+by Arch Linux. The poppler should be 0.83.0 or newer versions.
 POPPLER_VERSION should be defined.
 */
 
@@ -80,7 +79,7 @@ int main(int argc, char *argv[])
         exit(1);
     }
     fileName = new GString(argv[1]);
-    globalParams = new GlobalParams();
+    globalParams = std::make_unique<GlobalParams>();
     doc = new PDFDoc(fileName);
     if (!doc->isOk()) {
         fprintf(stderr, "Invalid PDF file\n");
@@ -100,8 +99,8 @@ int main(int argc, char *argv[])
     srcStream = Object(objNull);
     if (objnum == 0) {
         srcStream = catalogDict.dictLookup("SourceObject");
-        static char const_SourceFile[] = "SourceFile";
-        if (!srcStream.isStream(const_SourceFile)) {
+        static const char *const_SourceFile = "SourceFile";
+        if (!srcStream.isDict(const_SourceFile)) {
             fprintf(stderr, "No SourceObject found\n");
             exit(1);
         }
@@ -110,7 +109,7 @@ int main(int argc, char *argv[])
             fprintf(stderr, "No SourceName found\n");
             exit(1);
         }
-        outname = (char *)srcName.getString()->getCString();
+        outname = (char *)srcName.getString()->c_str();
         // We cannot free srcName, as objname shares its string.
         // srcName.free();
     } else if (objnum > 0) {
@@ -119,7 +118,7 @@ int main(int argc, char *argv[])
             fprintf(stderr, "Not a Stream object\n");
             exit(1);
         }
-        sprintf(buf, "%s", fileName->getCString());
+        sprintf(buf, "%s", fileName->c_str());
         if ((p = strrchr(buf, '.')) == 0)
             p = strchr(buf, 0);
         if (objgen == 0)
@@ -129,7 +128,7 @@ int main(int argc, char *argv[])
         outname = buf;
     } else {                    // objnum < 0 means we are extracting the XRef table
         extract_xref_table = true;
-        sprintf(buf, "%s", fileName->getCString());
+        sprintf(buf, "%s", fileName->c_str());
         if ((p = strrchr(buf, '.')) == 0)
             p = strchr(buf, 0);
         sprintf(p, ".xref");
@@ -162,7 +161,7 @@ int main(int argc, char *argv[])
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
@@ -204,5 +202,4 @@ int main(int argc, char *argv[])
         fprintf(stderr, "Cross-reference table extracted to %s\n", outname);
     fclose(outfile);
     delete doc;
-    delete globalParams;
 }
