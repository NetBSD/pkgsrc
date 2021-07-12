$NetBSD: patch-tests.mk,v 1.1 2021/07/12 21:32:49 schmonz Exp $

Explicitly run tests under OpenBSD ksh.

--- tests.mk.orig	2021-07-03 15:04:54.000000000 +0000
+++ tests.mk
@@ -3,7 +3,7 @@
 KEYLEN=4096
 
 test: tcps tcpc tlss tlsc server.crt client.crt ca.crt
-	./test.sh
+	oksh ./test.sh
 
 # create server key ############################################################
 client.key:
