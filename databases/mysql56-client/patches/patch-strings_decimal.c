$NetBSD: patch-strings_decimal.c,v 1.2 2013/04/29 21:16:57 joerg Exp $

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
@@ -353,7 +356,7 @@ int decimal2string(const decimal_t *from
   if (!(intg_len= fixed_precision ? fixed_intg : intg))
     intg_len= 1;
   frac_len= fixed_precision ? fixed_decimals : frac;
-  len= from->sign + intg_len + test(frac) + frac_len;
+  len= from->sign + intg_len + my_test(frac) + frac_len;
   if (fixed_precision)
   {
     if (frac > fixed_decimals)
@@ -387,7 +390,7 @@ int decimal2string(const decimal_t *from
     else
       frac-=j;
     frac_len= frac;
-    len= from->sign + intg_len + test(frac) + frac_len;
+    len= from->sign + intg_len + my_test(frac) + frac_len;
   }
   *to_len= len;
   s[len]= 0;
