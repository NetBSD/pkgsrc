$NetBSD: patch-src_lib_openjp2_tcd.c,v 1.1 2020/05/12 10:44:46 nia Exp $

CVE-2020-8112
https://github.com/uclouvain/openjpeg/commit/05f9b91e60debda0e83977e5e63b2e66486f7074.patch

--- src/lib/openjp2/tcd.c.orig	2019-04-02 12:45:15.000000000 +0000
+++ src/lib/openjp2/tcd.c
@@ -905,8 +905,24 @@ static INLINE OPJ_BOOL opj_tcd_init_tile
             /* p. 64, B.6, ISO/IEC FDIS15444-1 : 2000 (18 august 2000)  */
             l_tl_prc_x_start = opj_int_floordivpow2(l_res->x0, (OPJ_INT32)l_pdx) << l_pdx;
             l_tl_prc_y_start = opj_int_floordivpow2(l_res->y0, (OPJ_INT32)l_pdy) << l_pdy;
-            l_br_prc_x_end = opj_int_ceildivpow2(l_res->x1, (OPJ_INT32)l_pdx) << l_pdx;
-            l_br_prc_y_end = opj_int_ceildivpow2(l_res->y1, (OPJ_INT32)l_pdy) << l_pdy;
+            {
+                OPJ_UINT32 tmp = ((OPJ_UINT32)opj_int_ceildivpow2(l_res->x1,
+                                  (OPJ_INT32)l_pdx)) << l_pdx;
+                if (tmp > (OPJ_UINT32)INT_MAX) {
+                    opj_event_msg(manager, EVT_ERROR, "Integer overflow\n");
+                    return OPJ_FALSE;
+                }
+                l_br_prc_x_end = (OPJ_INT32)tmp;
+            }
+            {
+                OPJ_UINT32 tmp = ((OPJ_UINT32)opj_int_ceildivpow2(l_res->y1,
+                                  (OPJ_INT32)l_pdy)) << l_pdy;
+                if (tmp > (OPJ_UINT32)INT_MAX) {
+                    opj_event_msg(manager, EVT_ERROR, "Integer overflow\n");
+                    return OPJ_FALSE;
+                }
+                l_br_prc_y_end = (OPJ_INT32)tmp;
+            }
             /*fprintf(stderr, "\t\t\tprc_x_start=%d, prc_y_start=%d, br_prc_x_end=%d, br_prc_y_end=%d \n", l_tl_prc_x_start, l_tl_prc_y_start, l_br_prc_x_end ,l_br_prc_y_end );*/
 
             l_res->pw = (l_res->x0 == l_res->x1) ? 0U : (OPJ_UINT32)((
