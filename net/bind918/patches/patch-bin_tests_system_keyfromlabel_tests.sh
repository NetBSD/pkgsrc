$NetBSD: patch-bin_tests_system_keyfromlabel_tests.sh,v 1.1 2022/12/11 21:17:54 sekiya Exp $

Fix shell portability.

--- bin/tests/system/keyfromlabel/tests.sh.orig	2022-12-12 06:14:48.274390564 +0900
+++ bin/tests/system/keyfromlabel/tests.sh	2022-12-12 06:15:20.826375239 +0900
@@ -59,7 +59,7 @@
 		status=$((status+ret))
 
 		# Skip dnssec-keyfromlabel if key generation failed.
-		test $ret == 0 || continue
+		test $ret = 0 || continue
 
 		echo_i "Get ZSK $alg $zone $type:$bits"
 		ret=0
@@ -76,7 +76,7 @@
 		status=$((status+ret))
 
 		# Skip signing if dnssec-keyfromlabel failed.
-		test $ret == 0 || continue
+		test $ret = 0 || continue
 
 		echo_i "Sign zone with $ksk $zsk"
 		ret=0
