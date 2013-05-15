$NetBSD: patch-scanpci_scanpci.c,v 1.1 2013/05/15 03:20:16 richard Exp $

scanpci: print meaningful info on BASEROM

--- scanpci/scanpci.c.orig	2012-04-09 17:02:57.000000000 +0000
+++ scanpci/scanpci.c
@@ -47,6 +47,7 @@
 #endif
 
 #include "pciaccess.h"
+#include "pciaccess_private.h"
 
 
 static void
@@ -168,8 +169,11 @@ print_pci_device( struct pci_device * de
 	}
 
 	if ( dev->rom_size ) {
-	    printf( "  BASEROM   0x%08x  addr 0x%08x\n",
-		    0, 0 );
+	    struct pci_device_private *priv =
+		(struct pci_device_private *) dev;
+
+		printf( "  BASEROM   0x%08"PRIxPTR" SIZE %zu\n",
+			(intptr_t) priv->rom_base, (size_t) dev->rom_size);
 	}
 
 	pci_device_cfg_read_u8( dev, & int_pin, 61 );
