$NetBSD: patch-hints_netbsd.sh,v 1.5 2013/08/18 19:42:30 martin Exp $

--whole-archive is a linker flag, not a compiler flag
Better defaults for paths.

--- hints/netbsd.sh.orig	2013-05-01 04:52:55.000000000 +0200
+++ hints/netbsd.sh	2013-08-18 21:36:59.000000000 +0200
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
@@ -96,6 +96,9 @@
 	d_setprotoent_r="$undef"
 	d_endprotoent_r="$undef"
 	d_getservent_r="$undef"
+	d_gethostbyname_r="$undef"
+	d_gethostbyaddr_r="$undef"
+	d_gethostent_r="$undef"
 	d_getservbyname_r="$undef"
 	d_getservbyport_r="$undef"
 	d_setservent_r="$undef"
@@ -186,10 +189,12 @@
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
