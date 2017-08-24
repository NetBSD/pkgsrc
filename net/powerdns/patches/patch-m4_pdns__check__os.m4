$NetBSD: patch-m4_pdns__check__os.m4,v 1.1 2017/08/24 20:59:22 he Exp $

Don't insist on -latomic on mips & powerpc if on NetBSD.

--- m4/pdns_check_os.m4.orig	2017-06-22 20:07:25.000000000 +0000
+++ m4/pdns_check_os.m4
@@ -35,13 +35,20 @@ AC_DEFUN([PDNS_CHECK_OS],[
   AM_CONDITIONAL([HAVE_LINUX], [test "x$have_linux" = "xyes"])
   AM_CONDITIONAL([HAVE_SOLARIS], [test "x$have_solaris" = "xyes"])
 
-  case "$host" in
-  mips* | powerpc* )
-    AX_CHECK_LINK_FLAG([-latomic],
-      [ : ],
-      [ AC_MSG_ERROR([Unable to link against libatomic, cannot continue]) ]
-    )
-    LDFLAGS="-latomic $LDFLAGS"
+  case "$host_os" in
+  netbsd*)
+    : # no -latomic
+    ;;
+  *)
+    case "$host" in
+    mips* | powerpc* )
+      AX_CHECK_LINK_FLAG([-latomic],
+        [ : ],
+        [ AC_MSG_ERROR([Unable to link against libatomic, cannot continue]) ]
+      )
+      LDFLAGS="-latomic $LDFLAGS"
+      ;;
+    esac
     ;;
   esac
 
