$NetBSD: patch-conf-compile_defaults_host__link.sh,v 1.2 2018/05/28 12:00:39 schmonz Exp $

Find skalibs.

--- conf-compile/defaults/host_link.sh.orig	2015-03-28 22:14:58.223617960 +0000
+++ conf-compile/defaults/host_link.sh
@@ -3,4 +3,4 @@
 # variable $output names the library file to create.  The arguments are -L
 # search directives and the input object files and libraries.
 
-gcc -o "${output?}" -s ${1+"$@"}
+gcc ${LDFLAGS} -o "${output?}" -s ${1+"$@"}
