$NetBSD: patch-lib_utimens.h,v 1.1 2025/10/07 11:18:32 wiz Exp $

Add header for utimens().

--- libgnu_a-utimens.o ---
utimens.c: In function 'rpl_utimens':
utimens.c:541:10: error: implicit declaration of function 'utimens'; did you mean 'futimens'? [-Wimplicit-function-declaration]
  541 |   return utimens (file, timespec);
      |          ^~~~~~~
      |          futimens
utimens.c: In function 'rpl_lutimens':
utimens.c:563:10: error: implicit declaration of function 'lutimens'; did you mean 'futimens'? [-Wimplicit-function-declaration]
  563 |   return lutimens (file, timespec);
      |          ^~~~~~~~
      |          futimens
*** [libgnu_a-utimens.o] Error code 1

--- lib/utimens.h.orig	2025-10-07 11:13:03.489558332 +0000
+++ lib/utimens.h
@@ -25,6 +25,7 @@
 #include <time.h>
 
 #if HAVE_UTIMENS || HAVE_LUTIMENS
+# include <sys/stat.h>
 # include <sys/time.h>
 #endif
 
