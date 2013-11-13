$NetBSD: patch-hints_netbsd.sh,v 1.8 2013/11/13 13:36:02 joerg Exp $

--whole-archive is a linker flag, not a compiler flag
Better defaults for paths.
Stop grovelling for functions we don't want to provide (*host*)

--- hints/netbsd.sh.orig	2013-05-23 23:38:10.000000000 +0000
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
@@ -100,6 +90,12 @@ case "$osvers" in
 	d_getservbyport_r="$undef"
 	d_setservent_r="$undef"
 	d_endservent_r="$undef"
+	d_gethostbyname_r="$undef"
+	d_gethostbyaddr2_r="$undef"
+	d_gethostbyaddr_r="$undef"
+	d_sethostent_r="$undef"
+	d_gethostent_r="$undef"
+	d_endhostent_r="$undef"
 	d_getprotoent_r_proto="0"
 	d_getprotobyname_r_proto="0"
 	d_getprotobynumber_r_proto="0"
@@ -110,6 +106,12 @@ case "$osvers" in
 	d_getservbyport_r_proto="0"
 	d_setservent_r_proto="0"
 	d_endservent_r_proto="0"
+	d_gethostbyname_r_proto="0"
+	d_gethostbyaddr2_r_proto="0"
+	d_gethostbyaddr_r_proto="0"
+	d_sethostent_r_proto="0"
+	d_endhostent_r_proto="0"
+	d_gethostent_r_proto="0"
 	;;
 esac
 
@@ -186,10 +188,12 @@ esac
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
