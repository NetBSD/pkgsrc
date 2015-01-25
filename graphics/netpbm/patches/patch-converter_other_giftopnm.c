$NetBSD: patch-converter_other_giftopnm.c,v 1.1 2015/01/25 15:01:48 jperkin Exp $

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
