$NetBSD: patch-mkversion.sh,v 1.1 2025/06/12 10:59:31 hauke Exp $

Portability fix.

Choose plain sed over gsed.

--- mkversion.sh.orig	2025-04-29 23:11:07.000000000 +0000
+++ mkversion.sh
@@ -21,10 +21,7 @@
 
 VERSION_H=${1:-version.h}
 NEWFILE=`mktemp -t version.h.XXXXXXXXXX`
-SED=`command -v gsed 2> /dev/null`
-if [ $? != 0 ]; then
-	SED=`command -v sed`
-fi
+SED=`command -v sed 2> /dev/null`
 
 vinfo=0
 if [ -f .hg_archival.txt ]; then
@@ -52,7 +49,7 @@ if [ -f .hg_archival.txt ]; then
 	fi
 elif [ -d .hg ]; then
 	HG=${HG:-`command -v hg`}
-	if [ "$?" == "0" ]; then
+	if [ "$?" = "0" ]; then
 		# Check if we have modified, removed, added or deleted files.
 		if [ `$HG st -mard | wc -l` != "0" ]; then
 			# add delta indicator
@@ -62,7 +59,7 @@ elif [ -d .hg ]; then
 		fi
 		# Gather version information from repository and sandbox.
 		VER=`$HG id -T"{latesttag}{if(latesttagdistance,'.{latesttagdistance}')}" 2>/dev/null`
-		if [ $? == 0 ]; then
+		if [ $? = 0 ]; then
 			$HG log -r. -T"`cat version.t`" | $SED "s/\$DELTA/$DELTA/" > $NEWFILE
 		else
 			echo "warning: your mercurial version is too old"
