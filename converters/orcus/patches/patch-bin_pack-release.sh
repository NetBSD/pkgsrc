$NetBSD: patch-bin_pack-release.sh,v 1.1 2013/08/24 16:12:10 jaapb Exp $

Use proper test equality operator
--- bin/pack-release.sh.orig	2012-09-07 17:44:34.000000000 +0000
+++ bin/pack-release.sh
@@ -23,7 +23,7 @@ popd > /dev/null
 
 tar jcvfh $PACKAGE $DIR
 
-if [ "$1" == "md5" ]; then
+if [ "$1" = "md5" ]; then
     # prefix the package name with md5 sum.
     MD5SUM=`md5sum $PACKAGE | sed -e 's/\ .*//g'`
     mv $PACKAGE $MD5SUM-$PACKAGE
