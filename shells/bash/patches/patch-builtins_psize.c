$NetBSD: patch-builtins_psize.c,v 1.1 2022/11/25 23:29:47 adam Exp $

Use the definition of errno from <errno.h>.

--- builtins/psize.c.orig	2008-08-14 19:56:53.000000000 +0000
+++ builtins/psize.c
@@ -41,10 +41,6 @@
 #include "../general.h"
 #include "../sig.h"
 
-#ifndef errno
-extern int errno;
-#endif
-
 int nw;
 
 sighandler
