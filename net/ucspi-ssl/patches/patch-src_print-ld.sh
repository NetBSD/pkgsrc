$NetBSD: patch-src_print-ld.sh,v 1.1 2018/06/21 19:41:05 schmonz Exp $

Don't autodetect -m64.

--- src/print-ld.sh.orig	2016-08-02 11:32:28.000000000 +0000
+++ src/print-ld.sh
@@ -7,7 +7,8 @@ rm -f trycpp.o
 
 flag=`cc -c tryssl.c -m64 2>&1 | wc -l` 
 if [ $flag -eq 0 ]; then
-  ld="$ld -m64"
+  #ld="$ld -m64"
+  ld="$ld"
 fi
 
 rm -f trycpp.o
