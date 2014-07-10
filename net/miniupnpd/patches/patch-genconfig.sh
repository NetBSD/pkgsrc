$NetBSD: patch-genconfig.sh,v 1.1 2014/07/10 13:44:22 adam Exp $

Avoid firewall type auto-detection.

--- genconfig.sh.orig	2014-07-10 10:43:05.000000000 +0000
+++ genconfig.sh
@@ -293,7 +293,7 @@ case $OS_NAME in
 		;;
 esac
 
-case $FW in
+case @FWNAME@ in
 	pf)
 		echo "#define USE_PF 1" >> ${CONFIGFILE}
 		;;
