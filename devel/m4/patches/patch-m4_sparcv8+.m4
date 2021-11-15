$NetBSD: patch-m4_sparcv8+.m4,v 1.1 2021/11/15 13:20:04 nia Exp $

pkg/56498: "devel/m4" build fails on netbsd-9/sparc

--- m4/sparcv8+.m4.orig	2021-04-22 20:28:47.000000000 +0000
+++ m4/sparcv8+.m4
@@ -30,7 +30,7 @@ AC_DEFUN([gl_SPARC_V8PLUS],
              [gl_cv_sparc_v8plus=yes],
              [gl_cv_sparc_v8plus=no])
           ])
-        if test $gl_cv_sparc_v8plus = no; then
+        if test $gl_cv_sparc_v8plus != no; then
           dnl Strangely enough, '-mv8plus' does not have the desired effect.
           dnl But '-mcpu=v9' does.
           CC="$CC -mcpu=v9"
