$NetBSD: patch-gcc_lto_lto.c,v 1.1 2020/05/10 15:02:44 maya Exp $

Better fallback for netbsd<8 lacking WALLSIG.

--- gcc/lto/lto.c.orig	2018-01-03 21:42:12.000000000 +0000
+++ gcc/lto/lto.c
@@ -2321,7 +2321,11 @@ wait_for_child ()
   do
     {
 #ifndef WCONTINUED
-#define WCONTINUED 0
+#  ifdef WALLSIG
+#    define WCONTINUED WALLSIG
+#  else
+#    define WCONTINUED 0
+#  endif
 #endif
       int w = waitpid (0, &status, WUNTRACED | WCONTINUED);
       if (w == -1)
