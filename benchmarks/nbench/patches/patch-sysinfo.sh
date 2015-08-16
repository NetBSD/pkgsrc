$NetBSD: patch-sysinfo.sh,v 1.2 2015/08/16 06:39:45 mef Exp $

Avoid matching too many lines (trouble with gcc-4.5.3 on NetBSD)

--- sysinfo.sh~	2015-08-16 15:10:42.000000000 +0900
+++ sysinfo.sh	2015-08-16 15:11:19.000000000 +0900
@@ -19,7 +19,7 @@ fi
 compiler=`echo $* | sed -e 's/-static//g' -e 's/-Bstatic//g'`
 if $TEST `basename $1` = "gcc" && ($compiler -v) >/dev/null 2>&1 ; then
 # Cygwin writes more than one line with "version" in it
-    gccversion=`$compiler -v 2>&1 | sed -e "/version/!d" | tail -n 1`
+    gccversion=`$compiler -v 2>&1 | sed -e "/ version/!d" | tail -n 1`
 else
     gccversion="$1"
 fi
