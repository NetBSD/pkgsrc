$NetBSD: patch-pdftexdir_pdftosrc-newpoppler.cc,v 1.1 2018/05/13 13:01:02 markd Exp $

Build with poppler 0.64

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
