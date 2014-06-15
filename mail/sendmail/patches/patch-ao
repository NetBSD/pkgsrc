$NetBSD: patch-ao,v 1.3 2014/06/15 20:48:50 jnemeth Exp $

--- devtools/bin/install.sh.orig	2014-03-06 17:31:29.000000000 +0000
+++ devtools/bin/install.sh
@@ -101,25 +101,26 @@ then
 	$strip $dst
 fi
 
-# Change owner if requested
-if [ ! -z "$owner" ]
-then
-	$chown $owner $dst
-	if [ $? != 0 ]
-	then
-		exit 1
-	fi
-fi
-
-# Change group if requested
-if [ ! -z "$group" ]
-then
-	chgrp $group $dst
-	if [ $? != 0 ]
-	then
-		exit 1
-	fi
-fi
+# XXX Don't try to change owner or group, let pkgsrc infrastructure handle it.
+## Change owner if requested
+#if [ ! -z "$owner" ]
+#then
+#	$chown $owner $dst
+#	if [ $? != 0 ]
+#	then
+#		exit 1
+#	fi
+#fi
+#
+## Change group if requested
+#if [ ! -z "$group" ]
+#then
+#	chgrp $group $dst
+#	if [ $? != 0 ]
+#	then
+#		exit 1
+#	fi
+#fi
 
 # Change mode if requested
 if [ ! -z "$mode" ]
