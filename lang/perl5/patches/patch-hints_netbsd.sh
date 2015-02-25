$NetBSD: patch-hints_netbsd.sh,v 1.10 2015/02/25 14:56:45 wiz Exp $

--whole-archive is a linker flag, not a compiler flag
Better defaults for paths.
Stop grovelling for functions we don't want to provide (*host*)

--- hints/netbsd.sh.orig	2015-01-17 16:59:58.000000000 +0000
+++ hints/netbsd.sh
@@ -36,16 +36,6 @@ case "$osvers" in
 		d_dlerror=$define
 		cccdlflags="-DPIC -fPIC $cccdlflags"
 		lddlflags="-shared $lddlflags"
-		cat >UU/cc.cbu <<'EOCBU'
-# gcc 4.6 doesn't support --whole-archive, but it's required for the
-# system gcc to build correctly, so check for it
-echo 'int f(void) { return 0; }' >try.c
-if ${cc:-cc} $cccdlflags -c try.c -otry.o 2>&1 &&
-   ${cc:-cc} --whole-archive $lddlflags try.o -otry.so 2>&1 ; then
-    lddlflags="--whole-archive $lddlflags"
-fi
-rm try.c try.o try.so 2>/dev/null
-EOCBU
 		rpathflag="-Wl,-rpath,"
 		case "$osvers" in
 		1.[0-5]*)
@@ -200,10 +190,12 @@ esac
 EOCBU
 
 # Set sensible defaults for NetBSD: look for local software in
-# /usr/pkg (NetBSD Packages Collection) and in /usr/local.
+# /usr/local, plus the build prefix, which might or might not be
+# /usr/pkg.
 #
-loclibpth="/usr/pkg/lib /usr/local/lib"
-locincpth="/usr/pkg/include /usr/local/include"
+loclibpth="/usr/local/lib ${prefix}/lib"
+locincpth="/usr/local/include ${prefix}/include"
+
 case "$rpathflag" in
 '')
 	ldflags=
