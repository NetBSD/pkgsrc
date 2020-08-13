$NetBSD: patch-machine_sun_sun-bwtwo.c,v 1.1 2020/08/13 05:59:52 tsutsui Exp $

- Avoid a compiler bug (phantom integer oveflow) in gcc 4.5.3

--- machine/sun/sun-bwtwo.c.orig	2009-11-08 17:03:58.000000000 +0000
+++ machine/sun/sun-bwtwo.c
@@ -339,6 +339,7 @@ tme_sun_bwtwo(struct tme_element *elemen
 {
   struct tme_sunbw2 *sunbw2;
   int rc;
+  tme_uint16_t v;
 
   /* start the sunbw2 structure: */
   sunbw2 = tme_new0(struct tme_sunbw2, 1);
@@ -365,12 +366,10 @@ tme_sun_bwtwo(struct tme_element *elemen
   case TME_SUNBW2_TYPE_OLD_ONBOARD:
 
     /* set our initial CSR: */
-    sunbw2->tme_sunbw2_csr
-      = tme_htobe_u16(TME_SUNBW2_CSR_ENABLE_VIDEO
-		      | (sunbw2->tme_sunbw2_sunfb.tme_sunfb_size == TME_SUNFB_SIZE_1024_1024
-			 ? TME_SUNBW2_CSR_JUMPER_HIRES
-			 : 0));
-
+    v = TME_SUNBW2_CSR_ENABLE_VIDEO | (sunbw2->tme_sunbw2_sunfb.tme_sunfb_size
+				       == TME_SUNFB_SIZE_1024_1024
+				       ? TME_SUNBW2_CSR_JUMPER_HIRES : 0);
+    sunbw2->tme_sunbw2_csr = tme_htobe_u16(v);
     break;
   }
 
