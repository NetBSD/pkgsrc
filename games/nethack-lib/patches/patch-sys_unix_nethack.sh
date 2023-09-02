$NetBSD: patch-sys_unix_nethack.sh,v 1.3 2023/09/02 13:45:14 rhialto Exp $

Modify the wrapper script to find the app-defaults, the font path,
the nethack binary with the highest number of UIs.

--- sys/unix/nethack.sh.orig	2023-02-15 21:52:57.000000000 +0000
+++ sys/unix/nethack.sh
@@ -3,23 +3,56 @@
 # Copyright (c) 2015 by Kenneth Lorber, Kensington, Maryland
 # NetHack may be freely redistributed.  See license for details.
 
-HACKDIR=/usr/games/lib/nethackdir
+HACKDIR="@HACKDIR@"
 export HACKDIR
-HACK=$HACKDIR/nethack
 
-# Since Nethack.ad is installed in HACKDIR, add it to XUSERFILESEARCHPATH
+UILIST="curses tty" 
+if [ -n "$DISPLAY" ]
+then
+    UILIST="qt x11 $UILIST" 
+fi
+
+case "$1" in
+	qt|x11|curses|tty)
+	    echo "Please select the UI by putting 'windowtype:$1' in your \$NETHACKOPTIONS"
+	    echo "or 'OPTIONS=windowtype:$1' at the top of your \$HOME/.nethackrc file."
+	    exit 1
+	    ;;
+esac
+
+HACK=""
+
+for x in $UILIST
+do
+	if [ -x "@PREFIX@/bin/nethack-$x" ]
+	then
+		HACK="@PREFIX@/bin/nethack-$x"
+		break
+	fi
+done
+
+if [ -z "$HACK" ]
+then
+	echo "No UI found (nethack-$UILIST)"
+	exit 1
+fi
+
+# Since app-defaults/NetHack is installed in @PREFIX@/lib/X11,
+# add it to XUSERFILESEARCHPATH.
 case "x$XUSERFILESEARCHPATH" in
-x)	XUSERFILESEARCHPATH="$HACKDIR/%N.ad"
+x)	XUSERFILESEARCHPATH="@PREFIX@/lib/X11/app-defaults/%N"
 	;;
-*)	XUSERFILESEARCHPATH="$XUSERFILESEARCHPATH:$HACKDIR/%N.ad"
+*)	XUSERFILESEARCHPATH="$XUSERFILESEARCHPATH:@PREFIX@/lib/X11/app-defaults/%N"
 	;;
 esac
 export XUSERFILESEARCHPATH
 
 # Get font dir added, but only once (and only if there's an xset to be found).
-test -n "$DISPLAY" -a -f $HACKDIR/fonts.dir && xset p >/dev/null 2>&1 && (
-	xset fp- $HACKDIR >/dev/null 2>&1;
-	xset fp+ $HACKDIR
+test -n "$DISPLAY" -a -f @PREFIX@/share/fonts/X11/misc/fonts.dir && xset p >/dev/null 2>&1 && (
+	if ! xset q | grep @PREFIX@/share/fonts/X11/misc >/dev/null 2>&1
+	then
+	    xset fp+ @PREFIX@/share/fonts/X11/misc
+	fi
 )
 
 # see if we can find the full path name of PAGER, so help files work properly
