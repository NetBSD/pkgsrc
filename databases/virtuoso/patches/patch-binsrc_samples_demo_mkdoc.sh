$NetBSD: patch-binsrc_samples_demo_mkdoc.sh,v 1.1 2013/04/13 13:16:02 jaapb Exp $

Remove Makefiles from VAD content to eliminate buildlink references
--- binsrc/samples/demo/mkdoc.sh.orig	2012-08-01 20:54:30.000000000 +0000
+++ binsrc/samples/demo/mkdoc.sh
@@ -338,6 +338,7 @@ LOG "Directory init..."
 #  $CP docsrc/html_virt/*.ico vad/data/doc/html/.
 #  $CP docsrc/html_virt/*.rdf vad/data/doc/html/.
   $CP -R docsrc/html_virt vad/data/doc/html
+
   $CP docsrc/html_virt/*.css vad/data/doc/.
 
   $CP docsrc/images/*.jpg vad/data/doc/images/.
@@ -366,6 +367,7 @@ LOG "Directory init..."
   cp drop.sql vad/data/doc/code/.
   cp doc_sql_rdf.sql vad/data/doc/code/.
   #cp -f $HOME/binsrc/dav/DET_RDFData.sql vad/data/doc/code/.
+  find vad -name Makefile\* -exec rm -f \{\} \;
 }
 
 sticker_init() {
