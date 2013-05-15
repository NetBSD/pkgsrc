$NetBSD: patch-src_common__init.c,v 1.1 2013/05/15 03:20:16 richard Exp $

Solaris: Add domain support for sparc platform
As a result the code of finding nexus node for a device in sparc is simplified and made the same as x86. 

libpciaccess: fix memory usage errors
This patch fixes memory usage errors that only occur on large SPARC machines with more than 256 PCI devices. In this case, memory is being used after it has been freed by calls to both free() and realloc(). This error was introduced by a previous patch: 2011-03-30 Solaris support for multiple PCI segments (domains) 

--- src/common_init.c.orig	2012-04-09 17:02:57.000000000 +0000
+++ src/common_init.c
@@ -117,7 +117,6 @@ pci_system_cleanup( void )
 	pci_sys->num_devices = 0;
     }
 
-
     if ( pci_sys->methods->destroy != NULL ) {
 	(*pci_sys->methods->destroy)();
     }
