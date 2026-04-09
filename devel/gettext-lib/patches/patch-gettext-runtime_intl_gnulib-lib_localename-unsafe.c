$NetBSD: patch-gettext-runtime_intl_gnulib-lib_localename-unsafe.c,v 1.1 2026/04/09 08:48:44 jperkin Exp $

Remove bogus forward declaration.

--- gettext-runtime/intl/gnulib-lib/localename-unsafe.c.orig	2026-04-09 08:13:35.749112469 +0000
+++ gettext-runtime/intl/gnulib-lib/localename-unsafe.c
@@ -47,8 +47,6 @@
 # endif
 # if defined __sun
 #  if HAVE_GETLOCALENAME_L
-/* Solaris >= 12.  */
-extern char * getlocalename_l(int, locale_t);
 #  elif HAVE_SOLARIS114_LOCALES
 #   include <sys/localedef.h>
 #  endif
