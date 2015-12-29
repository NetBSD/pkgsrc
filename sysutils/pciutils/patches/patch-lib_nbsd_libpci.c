$NetBSD: patch-lib_nbsd_libpci.c,v 1.2 2015/12/29 04:04:31 dholland Exp $

--- lib/nbsd-libpci.c.orig	2011-01-08 06:04:28.000000000 +0900
+++ lib/nbsd-libpci.c	2015-11-12 17:45:08.000000000 +0900
@@ -71,7 +71,7 @@ nbsd_read(struct pci_dev *d, int pos, by
   if (!(len == 1 || len == 2 || len == 4))
     return pci_generic_block_read(d, pos, buf, len);
 
-  if (pos >= 256)
+  if (pos >= 4096)
     return 0;
 
   shift = 8*(pos % 4);
