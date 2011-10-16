$NetBSD: patch-build_rrd.sh,v 1.2 2011/10/16 15:19:09 spz Exp $

make it possible to deal with nonstandard locations of libpng* and libz*

--- build/rrd.sh.orig	2011-03-08 17:20:28.000000000 +0000
+++ build/rrd.sh
@@ -70,6 +70,12 @@
 	if test "$USERRRDLIB" != ""; then
 		RRDLIB="$USERRRDLIB"
 	fi
+	if test "$USERPNGCONFIG" != ""; then
+		PNGLIB=`$USERPNGCONFIG --ldflags`
+	fi
+	if test "$USERZLIB" != ""; then
+		ZLIB="$USERZLIB"
+	fi
 
 	if test -z "$RRDINC" -o -z "$RRDLIB"; then
 		echo "RRDtool include- or library-files not found. These are REQUIRED for Xymon"
