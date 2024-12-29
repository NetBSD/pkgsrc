$NetBSD: patch-chimera_ch__runtime.c,v 1.1 2024/12/29 14:56:38 adam Exp $

Do not use PCRE's internal function.

--- chimera/ch_runtime.c.orig	2024-12-29 12:38:10.000000000 +0000
+++ chimera/ch_runtime.c
@@ -120,7 +120,7 @@ struct HybridContext {
 };
 
 // Internal PCRE func.
-extern int _pcre_valid_utf(const unsigned char *, int, int *);
+//extern int _pcre_valid_utf(const unsigned char *, int, int *);
 
 /** UTF-8 validity check. Returns >0 if the given region of the data is valid
  * UTF-8, 0 otherwise. */
@@ -138,11 +138,11 @@ char isValidUTF8(struct HybridContext *h
 
     DEBUG_PRINTF("validating %d bytes\n", validate_len);
 
-    int erroroffset = 0;
-    if (_pcre_valid_utf(data, validate_len, &erroroffset)) {
-        DEBUG_PRINTF("UTF8 invalid at offset %d\n", erroroffset);
-        return 0;
-    }
+    //int erroroffset = 0;
+    //if (_pcre_valid_utf(data, validate_len, &erroroffset)) {
+    //    DEBUG_PRINTF("UTF8 invalid at offset %d\n", erroroffset);
+    //    return 0;
+    //}
 
     hyctx->valid_utf8_highwater = end;
     return 1;
