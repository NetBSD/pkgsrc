$NetBSD: patch-erts_aclocal.m4,v 1.1 2019/08/08 11:42:23 jperkin Exp $

SunOS needs -shared via the GCC driver, not -G.

--- erts/aclocal.m4.orig	2019-07-10 16:05:15.000000000 +0000
+++ erts/aclocal.m4
@@ -2983,7 +2983,7 @@ case $host_os in
 		DED_LD_FLAG_RUNTIME_LIBRARY_PATH=
 	;;
 	solaris2*|sysv4*)
-		DED_LDFLAGS="-G"
+		DED_LDFLAGS="-shared"
 		if test X${enable_m64_build} = Xyes; then
 			DED_LDFLAGS="-64 $DED_LDFLAGS"
 		fi
