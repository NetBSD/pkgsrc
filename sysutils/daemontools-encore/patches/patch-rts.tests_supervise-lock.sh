$NetBSD: patch-rts.tests_supervise-lock.sh,v 1.1 2020/01/25 11:17:31 schmonz Exp $

In ls(1) output from tests, omit any trailing SELinux dot.

--- rts.tests/supervise-lock.sh.orig	2018-10-14 00:48:50.000000000 +0000
+++ rts.tests/supervise-lock.sh
@@ -1,9 +1,9 @@
 echo '--- supervise leaves locked service intact'
 supervise test.sv &
 waitok test.sv
-( cd test.sv/supervise && ls -dl * | awk '{ print $1, $5, $9 }' )
+( cd test.sv/supervise && ls -dl * | awk '{ print substr($1,1,10), $5, $9 }' )
 supervise test.sv; echo $?
-( cd test.sv/supervise && ls -dl * | awk '{ print $1, $5, $9 }' )
+( cd test.sv/supervise && ls -dl * | awk '{ print substr($1,1,10), $5, $9 }' )
 svc -x test.sv; echo $?
 wait
 svstat test.sv; echo $?
