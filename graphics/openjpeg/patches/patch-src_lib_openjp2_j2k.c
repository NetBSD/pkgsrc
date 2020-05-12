$NetBSD: patch-src_lib_openjp2_j2k.c,v 1.1 2020/05/12 10:44:46 nia Exp $

CVE-2020-6851
https://github.com/uclouvain/openjpeg/commit/d7064fad0f8a2b485c4b520697e6741c6d94f5c5.patch

--- src/lib/openjp2/j2k.c.orig	2019-04-02 12:45:15.000000000 +0000
+++ src/lib/openjp2/j2k.c
@@ -9236,6 +9236,14 @@ static OPJ_BOOL opj_j2k_update_image_dim
     l_img_comp = p_image->comps;
     for (it_comp = 0; it_comp < p_image->numcomps; ++it_comp) {
         OPJ_INT32 l_h, l_w;
+        if( p_image->x0 > (OPJ_UINT32)INT_MAX ||
+            p_image->y0 > (OPJ_UINT32)INT_MAX ||
+            p_image->x1 > (OPJ_UINT32)INT_MAX ||
+            p_image->y1 > (OPJ_UINT32)INT_MAX ) {
+            opj_event_msg(p_manager, EVT_ERROR,
+                          "Image coordinates above INT_MAX are not supported\n");
+            return OPJ_FALSE;
+        }
 
         l_img_comp->x0 = (OPJ_UINT32)opj_int_ceildiv((OPJ_INT32)p_image->x0,
                          (OPJ_INT32)l_img_comp->dx);
