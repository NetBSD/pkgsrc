$NetBSD: patch-ioport.c,v 1.7 2013/06/16 18:27:25 tsutsui Exp $

Avoid conflicts with SSP read() macro in NetBSD's <ssp/unistd.h>
(PR lib/43832: ssp causes common names to be defines)

--- ioport.c.orig	2013-05-24 13:37:57.000000000 +0000
+++ ioport.c
@@ -183,7 +183,7 @@ static uint32_t ioport_readb_thunk(void 
     IORange *ioport = opaque;
     uint64_t data;
 
-    ioport->ops->read(ioport, addr - ioport->base, 1, &data);
+    (*ioport->ops->read)(ioport, addr - ioport->base, 1, &data);
     return data;
 }
 
@@ -192,7 +192,7 @@ static uint32_t ioport_readw_thunk(void 
     IORange *ioport = opaque;
     uint64_t data;
 
-    ioport->ops->read(ioport, addr - ioport->base, 2, &data);
+    (*ioport->ops->read)(ioport, addr - ioport->base, 2, &data);
     return data;
 }
 
@@ -201,7 +201,7 @@ static uint32_t ioport_readl_thunk(void 
     IORange *ioport = opaque;
     uint64_t data;
 
-    ioport->ops->read(ioport, addr - ioport->base, 4, &data);
+    (*ioport->ops->read)(ioport, addr - ioport->base, 4, &data);
     return data;
 }
 
