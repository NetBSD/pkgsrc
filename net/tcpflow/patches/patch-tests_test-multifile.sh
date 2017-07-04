$NetBSD: patch-tests_test-multifile.sh,v 1.1 2017/07/04 13:50:42 jperkin Exp $

Shell portability.

--- tests/test-multifile.sh.orig	2015-08-12 01:28:53.000000000 +0000
+++ tests/test-multifile.sh
@@ -93,7 +93,7 @@ do
   checkmd5 "$OUT/192.168.123.101.04660-110.045.186.224.01120" "dcd18bf7b6572443215154539a37d75c" "363"
   checkmd5 "$OUT/192.168.123.101.04661-110.045.186.224.01120" "d202ebd7c286d1ea4734bdbef69431c6" "323"
   checkmd5 "$OUT/202.043.063.139.00443-192.168.123.101.04591" "722c54c6443119b6c411359b9b7a47c2" "53"
-  if test $deldir == "yes" ; then
+  if test $deldir = "yes" ; then
     /bin/rm -rf $OUT
   fi
 done
