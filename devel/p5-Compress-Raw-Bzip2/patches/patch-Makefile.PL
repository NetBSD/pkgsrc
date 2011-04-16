$NetBSD: patch-Makefile.PL,v 1.1 2011/04/16 04:27:37 obache Exp $

  Record the path to the bzip2 library in the executable/library.
  COMPILER_RPATH_FLAG is specific to pkgsrc.

--- Makefile.PL.orig	2009-03-28 23:08:45.000000000 +0000
+++ Makefile.PL
@@ -37,7 +37,7 @@ WriteMakefile( 
     (
       $BUILD_BZIP2
         ? bzip2_files($BZIP2_LIB)
-        : (LIBS => [ "-L$BZIP2_LIB -lbz2 " ])
+        : (LIBS => [ "-L$BZIP2_LIB $ENV{'COMPILER_RPATH_FLAG'}$BZIP2_LIB -lbz2 " ])
     ),
       
     (
