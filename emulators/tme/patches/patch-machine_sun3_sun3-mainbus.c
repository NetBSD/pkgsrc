$NetBSD: patch-machine_sun3_sun3-mainbus.c,v 1.1 2013/02/26 23:39:18 joerg Exp $

--- machine/sun3/sun3-mainbus.c.orig	2013-02-26 21:51:46.000000000 +0000
+++ machine/sun3/sun3-mainbus.c
@@ -710,11 +710,11 @@ TME_ELEMENT_NEW_DECL(tme_machine_sun3) {
   /* try to read in the IDPROM: */
   idprom_fp = fopen(idprom_filename, "r");
   if (idprom_fp == NULL) {
-    tme_output_append_error(_output, idprom_filename);
+    tme_output_append_error(_output, "%s", idprom_filename);
     return (errno);
   }
   if (fread(idprom, sizeof(tme_uint8_t), sizeof(idprom), idprom_fp) != sizeof(idprom)) {
-    tme_output_append_error(_output, idprom_filename);
+    tme_output_append_error(_output, "%s", idprom_filename);
     fclose(idprom_fp);
     return (ENOEXEC);
   }
