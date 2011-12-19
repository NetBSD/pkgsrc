$NetBSD: patch-sysinfo.sh,v 1.1 2011/12/19 13:21:39 wiz Exp $

Avoid matching too many lines (trouble with gcc-4.5.3 on NetBSD)

--- sysinfo.sh.orig	2004-12-30 02:58:29.000000000 +0000
+++ sysinfo.sh
@@ -18,7 +18,7 @@ fi
 
 compiler=`echo $* | sed -e 's/-static//g' -e 's/-Bstatic//g'`
 if $TEST `basename $1` = "gcc" && ($compiler -v) >/dev/null 2>&1 ; then
-    gccversion=`$compiler -v 2>&1 | sed -e "/version/!d"`
+    gccversion=`$compiler -v 2>&1 | sed -e "/ version/!d"`
 else
     gccversion="$1"
 fi
