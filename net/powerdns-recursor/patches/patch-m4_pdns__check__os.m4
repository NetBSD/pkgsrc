$NetBSD: patch-m4_pdns__check__os.m4,v 1.3 2018/01/02 12:23:55 fhajny Exp $

Don't insist on -latomic on mips & powerpc if on NetBSD.

--- m4/pdns_check_os.m4.orig	2017-12-04 12:51:03.000000000 +0000
+++ m4/pdns_check_os.m4
@@ -35,14 +35,21 @@ AC_DEFUN([PDNS_CHECK_OS],[
   AM_CONDITIONAL([HAVE_LINUX], [test "x$have_linux" = "xyes"])
   AM_CONDITIONAL([HAVE_SOLARIS], [test "x$have_solaris" = "xyes"])
 
-  case "$host" in
-  mips* | powerpc-* )
-    AC_MSG_CHECKING([whether the linker accepts -latomic])
-    LDFLAGS="-latomic $LDFLAGS"
-    AC_LINK_IFELSE([m4_default([],[AC_LANG_PROGRAM()])],
-      [AC_MSG_RESULT([yes])],
-      [AC_MSG_ERROR([Unable to link against libatomic, cannot continue])]
-    )
+  case "$host_os" in
+  netbsd*)
+    : # no -latomic
+    ;;
+  *)
+    case "$host" in
+    mips* | powerpc-* )
+      AC_MSG_CHECKING([whether the linker accepts -latomic])
+      LDFLAGS="-latomic $LDFLAGS"
+      AC_LINK_IFELSE([m4_default([],[AC_LANG_PROGRAM()])],
+        [AC_MSG_RESULT([yes])],
+        [AC_MSG_ERROR([Unable to link against libatomic, cannot continue])]
+      )
+      ;;
+    esac
     ;;
   esac
 
