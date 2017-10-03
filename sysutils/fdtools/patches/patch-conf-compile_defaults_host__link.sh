$NetBSD: patch-conf-compile_defaults_host__link.sh,v 1.1 2017/10/03 00:43:22 schmonz Exp $

Find skalibs.

--- conf-compile/defaults/host_link.sh.orig	2015-03-28 22:14:58.000000000 +0000
+++ conf-compile/defaults/host_link.sh
@@ -3,4 +3,4 @@
 # variable $output names the library file to create.  The arguments are -L
 # search directives and the input object files and libraries.
 
-gcc -o "${output?}" -s ${1+"$@"}
+gcc -o "${output?}" -s -L ${PREFIX}/lib/skalibs ${1+"$@"}
