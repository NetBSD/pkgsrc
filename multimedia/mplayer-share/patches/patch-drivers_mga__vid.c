$NetBSD: patch-drivers_mga__vid.c,v 1.1 2025/11/15 12:43:17 ryoon Exp $

--- drivers/mga_vid.c.orig	2025-10-08 03:55:30.317078270 +0000
+++ drivers/mga_vid.c
@@ -138,14 +138,14 @@ static unsigned long simple_strtoul(cons
         if (*cp == '0') {
             base = 8;
             cp++;
-            if ((*cp == 'x') && isxdigit(cp[1])) {
+            if ((*cp == 'x') && isxdigit((unsigned char)(cp[1]))) {
                 cp++;
                 base = 16;
             }
         }
     }
-    while (isxdigit(*cp) && (value = isdigit(*cp) ? *cp-'0' : (islower(*cp)
-                                                               ? toupper(*cp) : *cp)-'A'+10) < base) {
+    while (isxdigit(*cp) && (value = isdigit((unsigned char)(*cp)) ? *cp-'0' : (islower((unsigned char)(*cp))
+                                                               ? toupper((unsigned char)(*cp)) : *cp)-'A'+10) < base) {
         result = result*base + value;
         cp++;
     }
