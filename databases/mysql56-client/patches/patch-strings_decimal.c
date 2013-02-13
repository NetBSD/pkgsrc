$NetBSD: patch-strings_decimal.c,v 1.1 2013/02/13 21:00:08 adam Exp $

* Portability: include <bstring.h> if exists.

--- strings/decimal.c.orig	2010-02-04 11:40:24.000000000 +0000
+++ strings/decimal.c
@@ -103,6 +103,9 @@
 #include <my_sys.h> /* for my_alloca */
 #include <m_string.h>
 #include <decimal.h>
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bzero() */
+#endif
 
 /*
   Internally decimal numbers are stored base 10^9 (see DIG_BASE below)
