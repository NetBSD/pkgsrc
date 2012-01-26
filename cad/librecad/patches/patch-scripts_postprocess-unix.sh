$NetBSD: patch-scripts_postprocess-unix.sh,v 1.1.1.1 2012/01/26 21:43:23 ryoon Exp $

* Set qt4 tools path
* Remove GNU find option

--- scripts/postprocess-unix.sh.orig	2012-01-18 05:38:57.000000000 +0000
+++ scripts/postprocess-unix.sh
@@ -7,7 +7,7 @@ DOCDIR="`pwd`/support/doc"
 
 # Generate Help Files
 cd "$DOCDIR"
-qcollectiongenerator LibreCADdoc.qhcp
+@QTDIR@/bin/qcollectiongenerator LibreCADdoc.qhcp
 
 cd "$THISDIR"
 
@@ -20,11 +20,11 @@ cp support/patterns/*.dxf $RESOURCEDIR/p
 cp support/fonts/*.lff* $RESOURCEDIR/fonts
 #cp support/doc/*.qhc $RESOURCEDIR/doc
 #cp support/doc/*.qch $RESOURCEDIR/doc
-find support/library -type d -not -path "*.svn*"  | sed s/support// | xargs -IFILES  mkdir $RESOURCEDIR/FILES
-find support/library -type f -iname *.dxf -not -path "*.svn*"  | sed s/support// | xargs -IFILES  cp support/FILES $RESOURCEDIR/FILES
+find support/library -type d  | sed s/support// | xargs -IFILES  mkdir $RESOURCEDIR/FILES
+find support/library -type f -iname *.dxf | sed s/support// | xargs -IFILES  cp support/FILES $RESOURCEDIR/FILES
 
 # Generate translations
-lrelease librecad.pro
+@QTDIR@/bin/lrelease librecad.pro
 mkdir -p $RESOURCEDIR/qm
  
 # Go into translations directory
