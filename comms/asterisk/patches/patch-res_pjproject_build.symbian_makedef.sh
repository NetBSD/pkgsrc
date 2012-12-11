$NetBSD: patch-res_pjproject_build.symbian_makedef.sh,v 1.1 2012/12/11 08:22:49 jnemeth Exp $

--- res/pjproject/build.symbian/makedef.sh.orig	2012-12-08 10:22:50.000000000 +0000
+++ res/pjproject/build.symbian/makedef.sh
@@ -1,13 +1,13 @@
 #!/bin/sh
 
 MMP=$1
-if test "$MMP" == ""; then
+if test "$MMP" = ""; then
 	echo "Usage: makedef.sh FILE.MMP"
 	echo "    or makedef.sh all"
 	exit 1
 fi
 
-if test "$MMP" == "all"; then
+if test "$MMP" = "all"; then
 	. $0 pjlib.mmp
 	. $0 pjlib_util.mmp
 	. $0 pjnath.mmp
