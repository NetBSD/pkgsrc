$NetBSD: patch-ocaml_libs_xb_xs__ring__stubs.c,v 1.1 2016/10/01 13:07:23 joerg Exp $

--- ocaml/libs/xb/xs_ring_stubs.c.orig	2016-09-30 12:57:34.000000000 +0000
+++ ocaml/libs/xb/xs_ring_stubs.c
@@ -46,8 +46,8 @@ static int xs_ring_read(struct mmap_inte
 	XENSTORE_RING_IDX cons, prod; /* offsets only */
 	int to_read;
 
-	cons = *(volatile uint32*)&intf->req_cons;
-	prod = *(volatile uint32*)&intf->req_prod;
+	cons = *(volatile uint32_t*)&intf->req_cons;
+	prod = *(volatile uint32_t*)&intf->req_prod;
 	xen_mb();
 
 	if ((prod - cons) > XENSTORE_RING_SIZE)
@@ -76,8 +76,8 @@ static int xs_ring_write(struct mmap_int
 	XENSTORE_RING_IDX cons, prod;
 	int can_write;
 
-	cons = *(volatile uint32*)&intf->rsp_cons;
-	prod = *(volatile uint32*)&intf->rsp_prod;
+	cons = *(volatile uint32_t*)&intf->rsp_cons;
+	prod = *(volatile uint32_t*)&intf->rsp_prod;
 	xen_mb();
 	if ( (prod - cons) >= XENSTORE_RING_SIZE )
 		return 0;
