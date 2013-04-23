$NetBSD: patch-src_descriptors_dr__7c.c,v 1.2 2013/04/23 13:22:22 wiz Exp $

clang fix, accepted upstream.

--- src/descriptors/dr_7c.c.orig	2013-02-25 14:29:08.000000000 +0000
+++ src/descriptors/dr_7c.c
@@ -245,7 +245,7 @@ dvbpsi_aac_dr_t *dvbpsi_DecodeAACDr(dvbp
     /* Keep additional info bytes field */
     if (p_descriptor->i_length > 1)
     {
-        uint8_t i_info_length = p_descriptor->i_length - p_decoded->b_type ? 3 : 2;
+        uint8_t i_info_length = p_descriptor->i_length - (p_decoded->b_type ? 3 : 2);
         dvbpsi_aac_dr_t *p_tmp = realloc(p_decoded, sizeof(dvbpsi_aac_dr_t) + i_info_length);
         if (!p_tmp)
         {
