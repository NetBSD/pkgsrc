$NetBSD: patch-src_target-based_sftarget__reader.c,v 1.2 2020/02/18 23:00:26 sevan Exp $

Sun ar needs at least one symbol in a library.

--- src/target-based/sftarget_reader.c.orig	2020-02-18 13:13:04.326915274 +0000
+++ src/target-based/sftarget_reader.c
@@ -31,6 +31,10 @@
 #define _GNU_SOURCE
 #endif
 
+#ifdef __sun
+int sun_ar_needs_a_symbol = 0;
+#endif
+
 #ifdef TARGET_BASED
 
 #include <stdio.h>
