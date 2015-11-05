$NetBSD: patch-kats_check-sums.sh,v 1.1 2015/11/05 08:50:33 wiz Exp $

Fix unportable test(1) operator.

--- kats/check-sums.sh.orig	2015-10-27 19:37:07.000000000 +0000
+++ kats/check-sums.sh
@@ -4,7 +4,7 @@ for file in `ls | grep '^[a-z2]*$' | xar
 do
     new=`shasum -a 256 $file`
     old=`cat $file.shasum`
-    if [ "$new" == "$old" ]
+    if [ "$new" = "$old" ]
     then
         echo $file "\t" OK
     else
