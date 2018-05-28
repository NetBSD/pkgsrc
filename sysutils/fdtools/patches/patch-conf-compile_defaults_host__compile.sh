$NetBSD: patch-conf-compile_defaults_host__compile.sh,v 1.2 2018/05/28 12:00:39 schmonz Exp $

Find skalibs.

--- conf-compile/defaults/host_compile.sh.orig	2015-03-28 22:14:58.219617961 +0000
+++ conf-compile/defaults/host_compile.sh
@@ -4,5 +4,5 @@
 # create, respectively.  The arguments are -I search directives; make sure to
 # include them in the compilation command.
 
-gcc -O2 ${1+"$@"} -c "${input?}" -o "${output?}" \
+gcc ${CFLAGS} ${CPPFLAGS} ${1+"$@"} -c "${input?}" -o "${output?}" \
   -Wall -W -Wpointer-arith -Wcast-align -Wwrite-strings
