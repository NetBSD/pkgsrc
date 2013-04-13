$NetBSD: patch-binsrc_samples_demo_make_vad.sh,v 1.1 2013/04/13 13:16:02 jaapb Exp $

Remove Makefiles from VAD content to eliminate buildlink references
--- binsrc/samples/demo/make_vad.sh.orig	2012-08-01 20:54:30.000000000 +0000
+++ binsrc/samples/demo/make_vad.sh
@@ -340,6 +340,7 @@ directory_init() {
   cp -f $HOME/binsrc/samples/webapp/forums/func_vad.sql             vad/data/demo/sql
 
   cp -f check_demo.sql                                          vad/data/demo/sql
+  find vad -name Makefile\* -exec rm -f \{\} \;
 }
 
 virtuoso_shutdown() {
