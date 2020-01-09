$NetBSD: patch-aclocal.m4,v 1.1 2020/01/09 12:32:24 pho Exp $

Canonicalize OS name netbsd* to "netbsd".

--- aclocal.m4.orig	2019-08-25 12:03:36.000000000 +0000
+++ aclocal.m4
@@ -2044,6 +2044,9 @@ AC_DEFUN([GHC_CONVERT_OS],[
       openbsd*)
         $3="openbsd"
         ;;
+      netbsd*)
+        $3="netbsd"
+        ;;
       # As far as I'm aware, none of these have relevant variants
       freebsd|netbsd|dragonfly|hpux|linuxaout|kfreebsdgnu|freebsd2|mingw32|darwin|nextstep2|nextstep3|sunos4|ultrix|haiku)
         $3="$1"
