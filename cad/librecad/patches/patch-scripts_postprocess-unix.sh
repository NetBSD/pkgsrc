$NetBSD: patch-scripts_postprocess-unix.sh,v 1.2 2012/08/18 06:58:15 ryoon Exp $

* Set qt4 tools path
* Remove GNU find option

--- scripts/postprocess-unix.sh.orig	2012-04-15 20:54:52.000000000 +0000
+++ scripts/postprocess-unix.sh
@@ -7,7 +7,7 @@ DOCDIR="${THISDIR}/support/doc"
 
 # Generate Help Files
 cd "{$DOCDIR}"
-qcollectiongenerator LibreCADdoc.qhcp
+@QTDIR@/bin/qcollectiongenerator LibreCADdoc.qhcp
 
 cd "${THISDIR}"
 
@@ -24,7 +24,7 @@ find support/library -type d | sed s/sup
 find support/library -type f -iname *.dxf | sed s/support// | xargs -IFILES  cp support/FILES "${RESOURCEDIR}"/FILES
 
 # Generate translations
-lrelease librecad.pro
+@QTDIR@/bin/lrelease librecad.pro
 mkdir -p "${RESOURCEDIR}"/qm
  
 # Go into translations directory
