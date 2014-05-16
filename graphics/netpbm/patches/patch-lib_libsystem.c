$NetBSD: patch-lib_libsystem.c,v 1.1 2014/05/16 12:43:52 ryoon Exp $

* For SIGWINCH and SIGIO, _XOPEN_SOURCE should not be defined under OpenBSD 5.5

--- lib/libsystem.c.orig	2010-07-10 01:38:01.000000000 +0000
+++ lib/libsystem.c
@@ -12,7 +12,10 @@
 
    Contributed to the public domain.
 =============================================================================*/
+/* for SIGWINCH and SIGIO */
+#if !defined(__OpenBSD__)
 #define _XOPEN_SOURCE
+#endif
 
 #include <unistd.h>
 #include <stdlib.h>
