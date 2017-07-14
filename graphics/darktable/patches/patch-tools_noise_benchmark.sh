$NetBSD: patch-tools_noise_benchmark.sh,v 1.3 2017/07/14 10:10:39 hauke Exp $

We bash bashisms.

--- tools/noise/benchmark.sh.orig	2017-05-28 14:22:21.000000000 +0000
+++ tools/noise/benchmark.sh
@@ -14,7 +14,7 @@ REF="reference.pfm"
 
 for i in *.pfm
 do
-  if [ "$i" == "$REF" ]
+  if [ "$i" = "$REF" ]
   then
     continue
   fi
