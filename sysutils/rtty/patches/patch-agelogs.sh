$NetBSD: patch-agelogs.sh,v 1.1 2021/09/10 08:28:21 he Exp $

Allow overriding the number of daily saved logs via
NLOGS environment variable.

--- agelogs.sh.orig	1996-08-23 22:25:26.000000000 +0000
+++ agelogs.sh
@@ -19,12 +19,14 @@
 
 agelog=/usr/etc/agelog
 
+nlogs=${NLOGS:-7}
+
 cd DESTPATH/dev
 for tty in *
 do
 	$agelog	-m DESTPATH/log/$tty \
 		-p `cat DESTPATH/pid/$tty` \
-		7 \
+		$nlogs \
 		DESTPATH/log/.aged
 done
 
