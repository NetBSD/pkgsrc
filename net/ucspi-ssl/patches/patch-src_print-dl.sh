$NetBSD: patch-src_print-dl.sh,v 1.1 2017/06/17 03:49:04 schmonz Exp $

Rather than try to detect -ldl, use known values. Fixes NetBSD build.

--- src/print-dl.sh.orig	2016-08-02 12:51:52.000000000 +0000
+++ src/print-dl.sh
@@ -1,5 +1,8 @@
 ssllib="`head -1 ../conf-ssllib`"
 
+echo "$ssllib ${DL_LIBS}"
+exit
+
 dlflag=0
 
 rm -f trycpp.o
