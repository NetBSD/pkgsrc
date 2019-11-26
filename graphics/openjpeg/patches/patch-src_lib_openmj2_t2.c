$NetBSD: patch-src_lib_openmj2_t2.c,v 1.2 2019/11/26 23:24:25 sevan Exp $

CVE-2018-16376
https://github.com/uclouvain/openjpeg/issues/1127
https://nvd.nist.gov/vuln/detail/CVE-2018-16376

--- src/lib/openmj2/t2.c.orig	2019-04-02 12:45:15.000000000 +0000
+++ src/lib/openmj2/t2.c
@@ -166,6 +166,15 @@ static int t2_encode_packet(opj_tcd_tile
 
     /* <SOP 0xff91> */
     if (tcp->csty & J2K_CP_CSTY_SOP) {
+	if (length < 6) {
+	    if (p_t2_mode == FINAL_PASS) {
+		opj_event_msg(p_manager, EVT_ERROR,
+				"opj_t2_encode_packet(): only %u bytes remaining in "
+				"output buffer. %u needed.\n",
+				length, 6);
+	    }
+	    return OPJ_FALSE;
+	}
         c[0] = 255;
         c[1] = 145;
         c[2] = 0;
@@ -272,6 +281,15 @@ static int t2_encode_packet(opj_tcd_tile
 
     /* <EPH 0xff92> */
     if (tcp->csty & J2K_CP_CSTY_EPH) {
+	if (length < 2) {
+	    if (p_t2_mode == FINAL_PASS) {
+		opj_event_msg(p_manager, EVT_ERROR,
+				"opj_t2_encode_packet(): only %u bytes remaining in "
+				"output buffer. %u needed.\n",
+				length, 2);
+	    }
+	    return OPJ_FALSE;
+	}
         c[0] = 255;
         c[1] = 146;
         c += 2;
