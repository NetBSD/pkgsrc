$NetBSD: patch-ioport.c,v 1.5 2012/06/07 21:23:46 ryoon Exp $

--- ioport.c.orig	2012-06-01 09:13:13.000000000 +0000
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
 
