$NetBSD: patch-utils_LIBtextio.c,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- utils/LIBtextio.c.orig	2013-03-02 22:24:58.000000000 +0000
+++ utils/LIBtextio.c
@@ -94,18 +94,23 @@ TxFlush()
  *
  * ----------------------------------------------------------------------------
  */
+void
+VTxError(char *fmt, va_list va)
+{
+    (void) fflush(stdout);
+    (void) fflush(stderr);
+    vfprintf(stderr, fmt, ap);
+    (void) fflush(stderr);
+}
 
 void
 TxError(char *fmt, ...)
 {
     va_list ap;
  
-    (void) fflush(stdout);
-    (void) fflush(stderr);
     va_start(ap, fmt);
-    vfprintf(stderr, fmt, ap);
+    VTxError(fmt, ap);
     va_end(ap);
-    (void) fflush(stderr);
 }
 
 
