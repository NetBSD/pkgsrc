$NetBSD: patch-bind_bind-9.11.14_bin_tests_system_metadata_tests.sh,v 1.1 2020/01/23 08:11:27 taca Exp $

Fix shell portability.

--- bind/bind-9.11.14/bin/tests/system/metadata/tests.sh.orig	2019-12-12 11:36:39.000000000 +0000
+++ bind/bind-9.11.14/bin/tests/system/metadata/tests.sh
@@ -137,7 +137,7 @@ status=`expr $status + $ret`
 
 echo_i "checking warning about permissions change on key with dnssec-settime ($n)"
 uname=`uname -o 2> /dev/null`
-if [ Cygwin == "$uname"  ]; then
+if [ Cygwin = "$uname"  ]; then
 	echo_i "Cygwin detected, skipping"
 else
 	ret=0
