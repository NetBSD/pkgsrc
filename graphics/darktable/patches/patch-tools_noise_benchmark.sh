$NetBSD: patch-tools_noise_benchmark.sh,v 1.1 2016/12/23 03:38:24 ryoon Exp $

--- tools/noise/benchmark.sh.orig	2016-12-11 18:49:55.000000000 +0000
+++ tools/noise/benchmark.sh
@@ -14,7 +14,7 @@ REF="reference.pfm"
 
 for i in *.pfm
 do
-  if [ "$i" == "$REF" ]
+  if [ "$i" = "$REF" ]
   then
     continue
   fi
