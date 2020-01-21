$NetBSD: patch-rts.tests_supervise-downtime.sh,v 1.1 2020/01/21 21:54:25 schmonz Exp $

Avoid GNUism.

--- rts.tests/supervise-downtime.sh.orig	2018-10-14 00:48:50.000000000 +0000
+++ rts.tests/supervise-downtime.sh
@@ -20,8 +20,8 @@ svpid=$!
 waitok test.sv
 
 svstat test.sv \
-| sed -r 's, \(.+\),,' \
-| sed -r 's, ([0-9]|1[0-9]) second.+$, ok,'
+| sed -E 's, \(.+\),,' \
+| sed -E 's, ([0-9]|1[0-9]) second.+$, ok,'
 
 kill $svpid
 wait
