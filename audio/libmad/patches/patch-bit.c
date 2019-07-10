$NetBSD: patch-bit.c,v 1.1 2019/07/10 20:01:57 nia Exp $

Fixes for CVE-2017-8372, CVE-2017-8373, CVE-2017-8374.

From Kurt Roeckx / Debian.

--- bit.c.orig	2004-01-23 09:41:32.000000000 +0000
+++ bit.c
@@ -138,6 +138,9 @@ unsigned long mad_bit_read(struct mad_bi
 {
   register unsigned long value;
 
+  if (len == 0)
+    return 0;
+
   if (bitptr->left == CHAR_BIT)
     bitptr->cache = *bitptr->byte;
 
