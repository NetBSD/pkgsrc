$NetBSD: patch-converter_other_giftopnm.c,v 1.2 2016/08/11 22:48:00 is Exp $

Fix "giftopnm.c:368: error: incompatible types in assignment".

--- converter/other/giftopnm.c.orig	2014-11-23 16:05:23.000000000 +0000
+++ converter/other/giftopnm.c
@@ -365,7 +365,7 @@ getDataBlock(FILE *          const ifP, 
         pm_message("EOF or error in reading DataBlock size from file.  %s",
                    error);
         pm_strfree(error);
-        *errorP = FALSE;
+        *errorP = NULL;
         *eofP = TRUE;
         *lengthP = 0;
     } else {
@@ -671,10 +671,13 @@ bitsOfLeBuffer(const unsigned char * con
 
     assert(len <= 16);
 
+/* should be UNALIGNED_OK, but that'd need fixing, too */
+#if defined(__vax__) || defined(__i486__) || defined(__x86_64__)
     if (BYTE_ORDER == LITTLE_ENDIAN)
         /* Fast path */
         codeBlock = *(uint32_t *) & buf[start/8];
     else
+#endif
         /* logic works for little endian too */
         codeBlock =
             (buf[start/8+0] <<  0) |
