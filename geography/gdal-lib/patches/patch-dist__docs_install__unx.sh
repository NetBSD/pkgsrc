$NetBSD: patch-dist__docs_install__unx.sh,v 1.1 2017/01/13 02:26:04 gdt Exp $

Remediate bashisms.
Not yet reported upstream.

--- dist_docs/install_unx.sh.orig	2016-07-01 08:55:08.000000000 +0000
+++ dist_docs/install_unx.sh
@@ -58,7 +58,7 @@ done
 cp share/gdal/* $PREFIX/share/gdal
 
 for EXECUTABLE in bin/* ; do
-  if test "$EXECUTABLE" == "bin/gdal-config" -o "$EXECUTABLE" == "bin/burnpath" ; then
+  if test "$EXECUTABLE" = "bin/gdal-config" -o "$EXECUTABLE" = "bin/burnpath" ; then
     /bin/true
   else
     cp $EXECUTABLE $PREFIX/bin
