$NetBSD: patch-qtgui_qmkmk.sh,v 1.1 2024/11/13 13:55:37 wiz Exp $

Hardcode ncpus to 2.
The sysctl|awk results in "=" on NetBSD, and we don't
want this to scale to ncpus in bulk build environment anyway.

--- qtgui/qmkmk.sh.orig	2024-11-13 13:23:22.684636962 +0000
+++ qtgui/qmkmk.sh
@@ -13,16 +13,6 @@ QMAKE=${QMAKE:-qmake}
 MAKE=${MAKE:-make}
 
 ncpus=2
-if which nproc > /dev/null ; then
-    ncpus=`nproc`
-elif which sysctl > /dev/null ; then
-    ncpus=`sysctl hw.ncpu | awk '{print $2}'`
-elif test -f /proc/cpuinfo ; then
-    ncpus=`grep -E '^processor[        ]*:' /proc/cpuinfo | wc -l`
-fi
-if test -z "$ncpus" ; then
-    ncpus=1
-fi
 
 cd $dir
 ${QMAKE} $fn $*
