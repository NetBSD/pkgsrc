$NetBSD: patch-sh.h,v 1.1 2014/05/25 03:59:17 rodent Exp $

Add OpenBSD support.

--- sh.h.orig	2011-04-14 18:25:25.000000000 +0000
+++ sh.h
@@ -310,7 +310,7 @@ typedef long tcsh_number_t;
  * redefines malloc(), so we define the following
  * to avoid it.
  */
-# if defined(SYSMALLOC) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__) || defined(sgi) || defined(_OSD_POSIX)
+# if defined(SYSMALLOC) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__) || defined(sgi) || defined(_OSD_POSIX) || defined(__OpenBSD__)
 #  define NO_FIX_MALLOC
 #  include <stdlib.h>
 # else /* glibc */
