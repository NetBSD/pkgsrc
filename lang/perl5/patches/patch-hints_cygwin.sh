$NetBSD: patch-hints_cygwin.sh,v 1.2 2025/02/18 11:49:55 wiz Exp $

* Remove broken settings.
* prevent to use C++ by default.

--- hints/cygwin.sh.orig	2024-02-27 00:50:15.000000000 +0000
+++ hints/cygwin.sh
@@ -28,11 +28,6 @@ libswanted=`echo " $libswanted " | sed -
 test -z "$ignore_versioned_solibs" && ignore_versioned_solibs='y'
 test -z "$usenm" && usenm='no'
 test -z "$libc" && libc='/usr/lib/libcygwin.a'
-test -z "$loclibpth" && loclibpth=' '
-test -z "$glibpth" && glibpth=' '
-test -z "$plibpth" && plibpth=' '
-test -z "$libpth" && libpth=' '
-PATH='.:/usr/bin/'
 # - add libgdbm_compat $libswanted
 libswanted="$libswanted gdbm_compat"
 test -z "$optimize" && optimize='-O3'
@@ -46,9 +41,8 @@ archname='cygwin'
 
 # dynamic loading
 # - otherwise -fpic
-cccdlflags=' '
 lddlflags=' --shared'
-test -z "$ld" && ld='g++'
+test -z "$ld" && ld="$cc"
 
 case "$osvers" in
     # Configure gets these wrong if the IPC server isn't yet running:
