$NetBSD: patch-aclocal.m4,v 1.4 2020/02/17 17:26:53 jperkin Exp $

Hunk #1:
  Don't require Alex to build. Fixed in upstream:
  https://gitlab.haskell.org/ghc/ghc/issues/16860

Hunk #2:
  Canonicalize OS name netbsd* to "netbsd":
  https://gitlab.haskell.org/ghc/ghc/merge_requests/2496

--- aclocal.m4.orig	2019-08-25 12:03:36.000000000 +0000
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
@@ -985,8 +985,11 @@ else
 fi;
 changequote([, ])dnl
 ])
-FP_COMPARE_VERSIONS([$fptools_cv_alex_version],[-lt],[3.1.7],
-  [AC_MSG_ERROR([Alex version 3.1.7 or later is required to compile GHC.])])[]
+if test ! -f compiler/parser/Lexer.hs
+then
+    FP_COMPARE_VERSIONS([$fptools_cv_alex_version],[-lt],[3.1.7],
+      [AC_MSG_ERROR([Alex version 3.1.7 or later is required to compile GHC.])])[]
+fi
 AlexVersion=$fptools_cv_alex_version;
 AC_SUBST(AlexVersion)
 ])
@@ -2044,6 +2047,9 @@ AC_DEFUN([GHC_CONVERT_OS],[
       openbsd*)
         $3="openbsd"
         ;;
+      netbsd*)
+        $3="netbsd"
+        ;;
       # As far as I'm aware, none of these have relevant variants
       freebsd|netbsd|dragonfly|hpux|linuxaout|kfreebsdgnu|freebsd2|mingw32|darwin|nextstep2|nextstep3|sunos4|ultrix|haiku)
         $3="$1"
