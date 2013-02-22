$NetBSD: patch-src_target-based_sftarget__reader.c,v 1.1 2013/02/22 12:05:34 jperkin Exp $

Sun ar needs at least one symbol in a library.

--- src/target-based/sftarget_reader.c.orig	2009-10-02 20:30:03.000000000 +0000
+++ src/target-based/sftarget_reader.c
@@ -26,6 +26,10 @@
 #include "config.h"
 #endif
 
+#ifdef __sun
+int sun_ar_needs_a_symbol = 0;
+#endif
+
 #ifdef TARGET_BASED
 
 #include <stdio.h>
