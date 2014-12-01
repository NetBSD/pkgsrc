$NetBSD: patch-strings_decimal.c,v 1.1.1.1 2014/12/01 05:58:03 jnemeth Exp $

* Portability: include <bstring.h> if exists.

--- strings/decimal.c.orig	2013-04-05 12:27:17.000000000 +0000
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
