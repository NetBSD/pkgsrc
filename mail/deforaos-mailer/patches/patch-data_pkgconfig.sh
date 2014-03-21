$NetBSD: patch-data_pkgconfig.sh,v 1.1 2014/03/21 14:00:57 jperkin Exp $

Use correct rpath flag on SunOS.

--- data/pkgconfig.sh.orig	2012-11-02 20:14:28.000000000 +0000
+++ data/pkgconfig.sh
@@ -107,6 +107,9 @@ while [ $# -gt 0 ]; do
 			Darwin)
 				RPATH="-Wl,-rpath,\${libdir}"
 				;;
+			SunOS)
+				RPATH="-Wl,-R\${libdir}"
+				;;
 		esac
 	fi
 
