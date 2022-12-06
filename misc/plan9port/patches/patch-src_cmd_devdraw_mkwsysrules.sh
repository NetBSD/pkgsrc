$NetBSD: patch-src_cmd_devdraw_mkwsysrules.sh,v 1.1 2022/12/06 14:29:25 vins Exp $

Add modular-xorg support for rio.

--- src/cmd/devdraw/mkwsysrules.sh.orig	2022-09-12 14:35:36.000000000 +0000
+++ src/cmd/devdraw/mkwsysrules.sh
@@ -17,6 +17,8 @@ if [ "x$X11" = "x" ]; then 
 		X11=/usr
 	elif [ -d /usr/local/include/X11 ]; then
 		X11=/usr/local
+	elif [ -d @PREFIX@/include/X11 ]; then
+		X11=@PREFIX@
 	else
 		X11=noX11dir
 	fi
