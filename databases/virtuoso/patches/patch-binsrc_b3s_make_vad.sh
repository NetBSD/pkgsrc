$NetBSD: patch-binsrc_b3s_make_vad.sh,v 1.1 2013/04/13 13:16:02 jaapb Exp $

Remove Makefiles from VAD content to eliminate buildlink references
--- binsrc/b3s/make_vad.sh.orig	2012-03-23 12:28:24.000000000 +0000
+++ binsrc/b3s/make_vad.sh
@@ -198,6 +198,8 @@ directory_init() {
 
   cat srank.sql | sed -e "s/, index rdf_quad_opgs//g" > vad/code/fct/srank_1.sql
 
+  find vad -name Makefile\* -exec rm -f \{\} \;
+
 }
 
 virtuoso_start() {
