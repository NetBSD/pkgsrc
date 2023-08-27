$NetBSD: patch-sys_unix_nethack.sh,v 1.2 2023/08/27 15:59:19 rhialto Exp $

Modify the wrapper script so users can choose the UI type on the
command line.

(Perhaps this should be handled by the pkg_alternatives framework.)

--- sys/unix/nethack.sh.orig	2019-05-08 07:00:16.000000000 +0000
+++ sys/unix/nethack.sh
@@ -3,9 +3,32 @@
 # Copyright (c) 2015 by Kenneth Lorber, Kensington, Maryland
 # NetHack may be freely redistributed.  See license for details.
 
-HACKDIR=/usr/games/lib/nethackdir
+HACKDIR="@HACKDIR@"
 export HACKDIR
-HACK=$HACKDIR/nethack
+
+UILIST="tty curses x11 qt" 
+findbin ()
+{
+	for x in $UILIST; do
+		if [ -x "@PREFIX@/bin/nethack-$x" ]; then
+			echo $x
+			return
+		fi
+	done
+}
+
+if [ -z "$1" -o -z "${1%%-*}" ]; then
+	UI=`findbin`
+else
+	UI=$1
+    shift
+fi
+
+if [ -z "$UI" ]; then
+	echo "No UI ($UILIST) found"
+	exit 1
+fi
+HACK="@PREFIX@/bin/nethack-${UI}"
 
 # Since Nethack.ad is installed in HACKDIR, add it to XUSERFILESEARCHPATH
 case "x$XUSERFILESEARCHPATH" in
