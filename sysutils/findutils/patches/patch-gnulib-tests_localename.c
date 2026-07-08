$NetBSD: patch-gnulib-tests_localename.c,v 1.1 2026/07/08 10:05:25 jperkin Exp $

Remove bogus forward declaration.

--- gnulib-tests/localename.c.orig	2026-07-08 10:01:29.521503103 +0000
+++ gnulib-tests/localename.c
@@ -45,8 +45,6 @@
 # include "glthread/lock.h"
 # if defined __sun
 #  if HAVE_GETLOCALENAME_L
-/* Solaris >= 12.  */
-extern char * getlocalename_l(int, locale_t);
 #  elif HAVE_SOLARIS114_LOCALES
 #   include <sys/localedef.h>
 #  endif
