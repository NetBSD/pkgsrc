$NetBSD: patch-scripts_auxiliar_cg-section.sh,v 1.1 2013/01/25 11:32:08 wiz Exp $

Fix unportable test(1) construct.

--- scripts/auxiliar/cg-section.sh.orig	2013-01-04 13:41:56.000000000 +0000
+++ scripts/auxiliar/cg-section.sh
@@ -31,7 +31,7 @@ EOF
     exit "$1"
 }
 
-if [ "$1" == '-h' ] || [ "$1" == '--help' ]; then
+if [ "$1" = '-h' ] || [ "$1" = '--help' ]; then
     usage 0
 fi
 
