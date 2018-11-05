$NetBSD: patch-hw_core_loader.c,v 1.1 2018/11/05 07:27:59 skrll Exp $

--- hw/core/loader.c.orig	2018-08-14 19:10:34.000000000 +0000
+++ hw/core/loader.c
@@ -637,13 +637,19 @@ static int load_uboot_image(const char *
         goto out;
 
     if (hdr->ih_type != image_type) {
-        fprintf(stderr, "Wrong image type %d, expected %d\n", hdr->ih_type,
-                image_type);
-        goto out;
+        if (image_type != IH_TYPE_KERNEL && hdr->ih_type != IH_TYPE_KERNEL_NOLOAD) {
+            fprintf(stderr, "Wrong image type %d, expected %d\n", hdr->ih_type,
+                    image_type);
+            goto out;
+        }
     }
 
     /* TODO: Implement other image types.  */
     switch (hdr->ih_type) {
+    case IH_TYPE_KERNEL_NOLOAD:
+        hdr->ih_load = *loadaddr + sizeof(*hdr);
+        hdr->ih_ep += hdr->ih_load;
+
     case IH_TYPE_KERNEL:
         address = hdr->ih_load;
         if (translate_fn) {
