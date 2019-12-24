$NetBSD: patch-liboctave_util_quit.cc,v 1.1 2019/12/24 01:58:48 dbj Exp $

Add missing header file for use of exit system call

--- liboctave/util/quit.cc.orig	2019-02-23 17:33:37.000000000 +0000
+++ liboctave/util/quit.cc
@@ -25,6 +25,7 @@ along with Octave; see the file COPYING.
 #endif
 
 #include <cstring>
+#include <cstdlib>
 
 #include <new>
 
