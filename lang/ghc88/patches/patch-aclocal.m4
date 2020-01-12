$NetBSD: patch-aclocal.m4,v 1.2 2020/01/12 08:13:41 pho Exp $

Hunk #1:
  Don't require Alex to build. Fixed in upstream:
  https://gitlab.haskell.org/ghc/ghc/issues/16860

Hunk #2:
  Canonicalize OS name netbsd* to "netbsd".

--- aclocal.m4.orig	2020-01-12 06:28:01.000000000 +0000
+++ aclocal.m4
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
