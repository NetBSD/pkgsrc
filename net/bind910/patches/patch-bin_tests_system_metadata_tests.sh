$NetBSD: patch-bin_tests_system_metadata_tests.sh,v 1.1 2018/03/24 15:02:32 taca Exp $

* Avoid using "==" for argument of test(1).

--- bin/tests/system/metadata/tests.sh.orig	2018-03-08 20:55:52.000000000 +0000
+++ bin/tests/system/metadata/tests.sh
@@ -146,7 +146,7 @@ status=`expr $status + $ret`
 
 echo "I:checking warning about permissions change on key with dnssec-settime ($n)"
 uname=`uname -o 2> /dev/null`
-if [ Cygwin == "$uname"  ]; then
+if [ Cygwin = "$uname"  ]; then
 	echo "I: Cygwin detected, skipping"
 else
 	ret=0
