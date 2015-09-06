$NetBSD: patch-test_rtpw__test.sh,v 1.1 2015/09/06 14:02:08 joerg Exp $

--- test/rtpw_test.sh.orig	2006-06-13 15:17:57.000000000 +0000
+++ test/rtpw_test.sh
@@ -4,7 +4,7 @@
 # 
 # tests the rtpw sender and receiver functions
 
-RTPW=rtpw
+RTPW=./rtpw
 DEST_PORT=9999
 DURATION=3
 
