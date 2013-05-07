$NetBSD: patch-logtail.sh,v 1.1 2013/05/07 08:49:28 wiz Exp $

# Replace stat arguments with NetBSD ones
--- work/logtail.sh.orig	2003-04-14 00:56:00.000000000 +0000
+++ work/logtail.sh	2013-05-05 07:23:46.000000000 +0000
@@ -29,9 +29,9 @@
 	[ -z "$SAVED_INODE" ] && SAVED_INODE=0
 	[ -z "$SAVED_POS"   ] && SAVED_POS=0
 
-	set abc `stat -lt $LOGFILE`
-	ACTUAL_LOGSIZE=$3
-	ACTUAL_INODE=$9
+	set abc `stat -f "%z %i" $LOGFILE`
+	ACTUAL_LOGSIZE=$2
+	ACTUAL_INODE=$3
 	$doit : $2, logsize=$ACTUAL_LOGSIZE, inode=$ACTUAL_INODE
 
 	[ -z "$ACTUAL_LOGSIZE" ] && ACTUAL_LOGSIZE=0
