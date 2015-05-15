$NetBSD: patch-hints_solaris__2.sh,v 1.1 2015/05/15 14:32:27 ryoon Exp $

Redo PR pkg/44999.

--- hints/solaris_2.sh.orig	2014-12-27 11:48:52.000000000 +0000
+++ hints/solaris_2.sh
@@ -622,7 +622,7 @@ EOM
 		# use that with Solaris 11 and later, but keep
 		# the old behavior for older Solaris versions.
 		case "$osvers" in
-			2.?|2.10) lddlflags="$lddlflags -G -m64" ;;
+			2.?|2.10) lddlflags="$lddlflags -shared -m64" ;;
 			*) lddlflags="$lddlflags -shared -m64" ;;
 		esac
 		;;
