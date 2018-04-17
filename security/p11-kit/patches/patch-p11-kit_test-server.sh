$NetBSD: patch-p11-kit_test-server.sh,v 1.1 2018/04/17 13:26:15 wiz Exp $

Fix unportable test(1) operator.

--- p11-kit/test-server.sh.orig	2018-01-31 12:47:38.000000000 +0000
+++ p11-kit/test-server.sh
@@ -24,8 +24,8 @@ fi
 
 . ./start.env
 
-test "${P11_KIT_SERVER_ADDRESS+set}" == set || exit 1
-test "${P11_KIT_SERVER_PID+set}" == set || exit 1
+test "${P11_KIT_SERVER_ADDRESS+set}" = set || exit 1
+test "${P11_KIT_SERVER_PID+set}" = set || exit 1
 
 "$abs_top_builddir"/p11-kit-server -s -k > stop.env 2> stop.err
 if test $? -ne 0; then
@@ -35,5 +35,5 @@ fi
 
 . ./stop.env
 
-test "${P11_KIT_SERVER_ADDRESS-unset}" == unset || exit 1
-test "${P11_KIT_SERVER_PID-unset}" == unset || exit 1
+test "${P11_KIT_SERVER_ADDRESS-unset}" = unset || exit 1
+test "${P11_KIT_SERVER_PID-unset}" = unset || exit 1
