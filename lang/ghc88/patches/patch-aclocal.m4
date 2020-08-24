$NetBSD: patch-aclocal.m4,v 1.5 2020/08/24 17:23:12 pho Exp $

Hunk #1:
  Support SunOS/x86_64.

Hunk #2:
  Canonicalize OS name netbsd* to "netbsd":
  https://gitlab.haskell.org/ghc/ghc/merge_requests/2496

--- aclocal.m4.orig	2020-07-08 16:43:03.000000000 +0000
+++ aclocal.m4
@@ -661,7 +661,7 @@ AC_DEFUN([FPTOOLS_SET_C_LD_FLAGS],
     x86_64-unknown-solaris2)
         $2="$$2 -m64"
         $3="$$3 -m64"
-        $4="$$4 -m64"
+        $4="$$4 -64"
         $5="$$5 -m64"
         ;;
     alpha-*)
@@ -2047,6 +2047,9 @@ AC_DEFUN([GHC_CONVERT_OS],[
       openbsd*)
         $3="openbsd"
         ;;
+      netbsd*)
+        $3="netbsd"
+        ;;
       # As far as I'm aware, none of these have relevant variants
       freebsd|netbsd|dragonfly|hpux|linuxaout|kfreebsdgnu|freebsd2|mingw32|darwin|nextstep2|nextstep3|sunos4|ultrix|haiku)
         $3="$1"
