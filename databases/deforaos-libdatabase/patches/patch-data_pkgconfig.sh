$NetBSD: patch-data_pkgconfig.sh,v 1.1 2014/03/21 13:59:27 jperkin Exp $

Use correct rpath flag on SunOS.

--- data/pkgconfig.sh.orig	2013-01-27 03:39:44.000000000 +0000
+++ data/pkgconfig.sh
@@ -114,6 +114,9 @@ while [ $# -gt 0 ]; do
 			Darwin)
 				RPATH="-Wl,-rpath,\${libdir}"
 				;;
+			SunOS)
+				RPATH="-Wl,-R\${libdir}"
+				;;
 		esac
 	fi
 
