$NetBSD: patch-lookup3.c,v 1.1 2011/04/01 21:28:32 tez Exp $

Don't include stdint.h if it does not exist.  Fixes PR#44770

--- lookup3.c.orig	2011-04-01 21:06:28.047391300 +0000
+++ lookup3.c
@@ -34,7 +34,9 @@
 */
 /* -------------------------------------------------------------------- */
 
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 #if defined(_JLU3_SELFTEST)
 # define _JLU3_jlu32w		1
