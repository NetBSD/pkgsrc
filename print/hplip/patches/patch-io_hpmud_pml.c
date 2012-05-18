$NetBSD: patch-io_hpmud_pml.c,v 1.1.1.1 2012/05/18 03:03:22 schnoebe Exp $

Should fix CVE-2010-4267 according to:
https://bugzilla.redhat.com/attachment.cgi?id=468455&action=diff

--- io/hpmud/pml.c.orig	2011-05-14 18:26:04.000000000 +0000
+++ io/hpmud/pml.c
@@ -504,6 +504,8 @@ enum HPMUD_RESULT hpmud_get_pml(HPMUD_DE
       p += 2;                               /* eat type and length */
    }
    
+   if (dLen > buf_size)
+      dLen = buf_size;
    memcpy(buf, p, dLen);
    *bytes_read = dLen; 
    *type = dt;
