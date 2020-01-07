$NetBSD: patch-aclocal.m4,v 1.1 2020/01/07 16:52:09 pho Exp $

Canonicalize OS name netbsd* to "netbsd".

--- aclocal.m4.orig	2020-01-04 06:53:44.706301052 +0000
+++ aclocal.m4
@@ -1981,6 +1981,9 @@ AC_DEFUN([GHC_CONVERT_OS],[
       openbsd*)
         $3="openbsd"
         ;;
+      netbsd*)
+        $3="netbsd"
+        ;;
       # As far as I'm aware, none of these have relevant variants
       freebsd|netbsd|dragonfly|hpux|linuxaout|kfreebsdgnu|freebsd2|mingw32|darwin|gnu|nextstep2|nextstep3|sunos4|ultrix|haiku)
         $3="$1"
