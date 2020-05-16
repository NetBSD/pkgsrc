$NetBSD: patch-src_formula.cpp,v 1.1 2020/05/16 02:12:23 joerg Exp $

Tell ghostscript that we want to read files from the local directory.
With 9.50+, SAFER is enabled by default and it can't read the EPS otherwise.

--- src/formula.cpp.orig	2020-05-16 01:35:49.487162414 +0000
+++ src/formula.cpp
@@ -180,7 +180,7 @@ void FormulaList::generateBitmaps(const 
       // used.  
 
       char gsArgs[4096];
-      sprintf(gsArgs,"-q -g%dx%d -r%dx%dx -sDEVICE=ppmraw "
+      sprintf(gsArgs,"-q -g%dx%d -r%dx%dx -sDEVICE=ppmraw -I. "
                     "-sOutputFile=%s.pnm -dNOPAUSE -dBATCH -- %s.ps",
                     gx,gy,(int)(scaleFactor*72),(int)(scaleFactor*72),
                     formBase.data(),formBase.data()
