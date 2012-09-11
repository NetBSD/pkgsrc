$NetBSD: patch-ioport.c,v 1.6 2012/09/11 17:13:45 asau Exp $

--- ioport.c.orig	2012-09-05 14:03:06.000000000 +0000
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
 
