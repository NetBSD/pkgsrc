$NetBSD: patch-m4_pdns__check__os.m4,v 1.2 2017/08/02 20:15:42 fhajny Exp $

Third argument is a instruction list.

--- m4/pdns_check_os.m4.orig	2017-07-04 15:43:07.000000000 +0000
+++ m4/pdns_check_os.m4
@@ -37,11 +37,8 @@ AC_DEFUN([PDNS_CHECK_OS],[
 
   case "$host" in
   mips* | powerpc* )
-    AX_CHECK_LINK_FLAG([-latomic],
-      [ : ],
-      [ AC_MSG_ERROR([Unable to link against libatomic, cannot continue]) ]
-    )
-    LDFLAGS="-latomic $LDFLAGS"
+    AX_CHECK_LINK_FLAG([-latomic],[LDFLAGS="-latomic $LDFLAGS"]
+      [AC_MSG_ERROR([Unable to link against libatomic, cannot continue])])
     ;;
   esac
 
