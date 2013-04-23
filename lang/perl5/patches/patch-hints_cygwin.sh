$NetBSD: patch-hints_cygwin.sh,v 1.1 2013/04/23 12:22:36 obache Exp $

* prevent to use C++ by default.

--- hints/cygwin.sh.orig	2013-03-04 15:16:22.000000000 +0000
+++ hints/cygwin.sh
@@ -39,7 +39,7 @@ archname='cygwin'
 # - otherwise -fpic
 cccdlflags=' '
 lddlflags=' --shared'
-test -z "$ld" && ld='g++'
+test -z "$ld" && ld="$cc"
 
 case "$osvers" in
     # Configure gets these wrong if the IPC server isn't yet running:
