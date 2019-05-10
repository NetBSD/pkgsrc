$NetBSD: patch-pdftexdir_pdftosrc-newpoppler.cc,v 1.5 2019/05/10 19:19:09 ryoon Exp $

--- pdftexdir/pdftosrc-newpoppler.cc.orig	2017-10-17 21:52:13.000000000 +0000
+++ pdftexdir/pdftosrc-newpoppler.cc
@@ -20,7 +20,7 @@ with this program.  If not, see <http://
 /*
 This is based on the patch texlive-poppler-0.59.patch <2017-09-19> at
 https://git.archlinux.org/svntogit/packages.git/plain/texlive-bin/trunk
-by Arch Linux. The poppler should be 0.59.0 or newer versions.
+by Arch Linux. The poppler should be 0.76.0 or newer versions.
 POPPLER_VERSION should be defined.
 */
 
@@ -109,7 +109,7 @@ int main(int argc, char *argv[])
             fprintf(stderr, "No SourceName found\n");
             exit(1);
         }
-        outname = srcName.getString()->getCString();
+        outname = (char *)srcName.getString()->c_str();
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
@@ -173,9 +173,8 @@ int main(int argc, char *argv[])
 
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
