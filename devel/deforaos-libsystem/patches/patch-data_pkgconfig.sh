$NetBSD: patch-data_pkgconfig.sh,v 1.2 2014/09/16 19:25:51 khorben Exp $

Use correct rpath flag on SunOS.

--- data/pkgconfig.sh.orig	2014-04-23 15:37:45.000000000 +0000
+++ data/pkgconfig.sh
@@ -129,9 +129,12 @@ while [ $# -gt 0 ]; do
 	if [ "$PREFIX" != "/usr" ]; then
 		RPATH="-Wl,-rpath-link,\${libdir} -Wl,-rpath,\${libdir}"
 		case $(uname -s) in
-			Darwin|SunOS)
+			Darwin)
 				RPATH="-Wl,-rpath,\${libdir}"
 				;;
+			SunOS)
+				RPATH="-Wl,-R\${libdir}"
+				;;
 		esac
 	fi
 
