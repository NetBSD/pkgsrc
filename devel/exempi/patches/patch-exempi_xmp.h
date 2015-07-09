$NetBSD: patch-exempi_xmp.h,v 1.1 2015/07/09 13:53:51 richard Exp $

should no longer be necessary on modern Solaris, but just in case.

--- exempi/xmp.h.orig	2014-08-31 22:03:10.000000000 +0000
+++ exempi/xmp.h
@@ -41,7 +41,7 @@
 
 #include <stdlib.h>
 /* stdbool choke on Sun (bug #14612) */
-#if !defined(__sun)
+#if ! (defined(__sun) && defined(__cplusplus))
 #include <stdbool.h>
 #endif
 #include <stdint.h>
