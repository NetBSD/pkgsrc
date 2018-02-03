$NetBSD: patch-src_lisp.h,v 1.1 2018/02/03 20:26:31 kamil Exp $

Port to NetBSD.

--- src/lisp.h.orig	2015-07-22 00:49:58.000000000 +0000
+++ src/lisp.h
@@ -39,6 +39,9 @@
 #if RTPC
 #   undef    IBM_RT_AIX
 #   define   IBM_RT_AIX           1
+#elif defined(__NetBSD__)
+#   undef    BERKELEY_UNIX
+#   define   BERKELEY_UNIX        1
 #else
 #   if RS6000
 #      undef   IBM_RT_AIX
@@ -1183,8 +1186,3 @@ extern int      liScanLineNum;          
 #define OPK_LIT2      4           /* has two <lit> args */
 #define OPK_INTERNAL  5           /* state change operation, arguments are internal to byte machine */
 #define OPK_N1        6           /* operation uses a single <n> argument */
-
-
-
-
-
