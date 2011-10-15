$NetBSD: patch-build_rrd.sh,v 1.1 2011/10/15 23:07:24 spz Exp $

--- build/rrd.sh.orig	2011-03-08 17:20:28.000000000 +0000
+++ build/rrd.sh
@@ -70,6 +70,12 @@
 	if test "$USERRRDLIB" != ""; then
 		RRDLIB="$USERRRDLIB"
 	fi
+	if test "$USERPNGLIB" != ""; then
+		PNGLIB="$USERPNGLIB"
+	fi
+	if test "$USERZLIB" != ""; then
+		ZLIB="$USERZLIB"
+	fi
 
 	if test -z "$RRDINC" -o -z "$RRDLIB"; then
 		echo "RRDtool include- or library-files not found. These are REQUIRED for Xymon"
