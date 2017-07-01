$NetBSD: patch-m4_acx__check__suncc.m4,v 1.1 2017/07/01 15:26:52 jperkin Exp $

Disable Solaris ISA selection.

--- m4/acx_check_suncc.m4.orig	2017-03-29 20:41:23.000000000 +0000
+++ m4/acx_check_suncc.m4
@@ -30,7 +30,7 @@ AC_DEFUN([ACX_CHECK_SUNCC],[
   ])
 
   case $host_os in
-    *solaris*)
+    *notsolaris*)
       AC_CHECK_PROGS(ISAINFO, [isainfo], [no])
       AS_IF([test "x$ISAINFO" != "xno"],
             [isainfo_b=`${ISAINFO} -b`],
