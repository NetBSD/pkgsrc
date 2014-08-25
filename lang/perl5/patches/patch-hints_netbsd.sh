$NetBSD: patch-hints_netbsd.sh,v 1.8.6.1 2014/08/25 09:17:26 spz Exp $

--whole-archive is a linker flag, not a compiler flag
Better defaults for paths.
Stop grovelling for functions we don't want to provide (*host*)

--- hints/netbsd.sh.orig	2014-08-11 22:30:50.000000000 -0700
+++ hints/netbsd.sh	2014-08-11 22:32:13.000000000 -0700
@@ -36,16 +36,6 @@
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
@@ -89,7 +79,9 @@
 	;;
 esac
 case "$osvers" in
-0.9*|1.*|2.*|3.*|4.*|5.*|6.*)
+0.8*)
+	;;
+*)
 	d_getprotoent_r="$undef"
 	d_getprotobyname_r="$undef"
 	d_getprotobynumber_r="$undef"
@@ -100,6 +92,12 @@
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
@@ -110,6 +108,12 @@
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
 
@@ -186,10 +190,12 @@
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
