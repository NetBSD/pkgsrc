$NetBSD: patch-lib_utimens.h,v 1.1 2026/08/23 18:46:55 wiz Exp $

* lib/utimens.h [HAVE_UTIMENS || HAVE_LUTIMENS]: Include <sys/stat.h>
instead of <sys/time.h> for the declarations of these functions on
NetBSD.

https://debbugs.gnu.org/cgi/bugreport.cgi?bug=81231

--- lib/utimens.h.orig	2026-06-14 18:08:28.940590875 +0000
+++ lib/utimens.h
@@ -25,7 +25,7 @@
 #include <time.h>
 
 #if HAVE_UTIMENS || HAVE_LUTIMENS
-# include <sys/time.h>
+# include <sys/stat.h>
 #endif
 
 #ifdef __cplusplus
