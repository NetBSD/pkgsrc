$NetBSD: patch-hints_netbsd.sh,v 1.7 2013/08/19 12:31:11 christos Exp $

--whole-archive is a linker flag, not a compiler flag
Better defaults for paths.
Stop grovelling for functions we don't want to provide (*host*)

--- hints/netbsd.sh.orig	2013-08-19 21:23:34.000000000 +0300
+++ hints/netbsd.sh	2013-08-19 21:23:12.000000000 +0300
@@ -41,8 +41,8 @@
 # system gcc to build correctly, so check for it
 echo 'int f(void) { return 0; }' >try.c
 if ${cc:-cc} $cccdlflags -c try.c -otry.o 2>&1 &&
-   ${cc:-cc} --whole-archive $lddlflags try.o -otry.so 2>&1 ; then
-    lddlflags="--whole-archive $lddlflags"
+   ${cc:-cc} -Wl,--whole-archive $lddlflags try.o -otry.so 2>&1 ; then
+    lddlflags="-Wl,--whole-archive $lddlflags"
 fi
 rm try.c try.o try.so 2>/dev/null
 EOCBU
@@ -100,6 +100,12 @@
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
@@ -110,6 +116,12 @@
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
 
@@ -186,10 +198,12 @@
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
