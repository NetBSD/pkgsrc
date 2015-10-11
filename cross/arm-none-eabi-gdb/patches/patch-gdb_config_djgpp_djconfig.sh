$NetBSD: patch-gdb_config_djgpp_djconfig.sh,v 1.1 2015/10/11 01:15:18 ryoon Exp $

--- gdb/config/djgpp/djconfig.sh.orig	2015-02-19 11:58:07.000000000 +0000
+++ gdb/config/djgpp/djconfig.sh
@@ -92,7 +92,7 @@ TMPFILE="${TMPDIR-.}/cfg.tmp"
 
 # We need to skip the build directory if it is a subdirectory of $srcdir,
 # otherwise we will have an infinite recursion on our hands...
-if test "`pwd`" == "${srcdir}" ; then
+if test "`pwd`" = "${srcdir}" ; then
   SKIPDIR=""
   SKIPFILES=""
 else
