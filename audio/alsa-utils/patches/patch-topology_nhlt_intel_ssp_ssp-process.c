$NetBSD: patch-topology_nhlt_intel_ssp_ssp-process.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- topology/nhlt/intel/ssp/ssp-process.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ topology/nhlt/intel/ssp/ssp-process.c
@@ -14,6 +14,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdbool.h>
+#include <alsa/global.h>
 #include <alsa/input.h>
 #include <alsa/output.h>
 #include <alsa/conf.h>
@@ -25,7 +26,7 @@
 #include "ssp-internal.h"
 #include "ssp-debug.h"
 
-static int popcount(uint32_t value)
+static int alpopcount(uint32_t value)
 {
 	int bits_set = 0;
 
@@ -431,8 +432,8 @@ static int ssp_calculate_intern(struct i
 		 */
 		ssp->ssp_blob[di][hwi].sspsp |= SSPSP_SFRMP(!inverted_frame ? 1 : 0);
 
-		active_tx_slots = popcount(ssp->ssp_prm[di].hw_cfg[hwi].tx_slots);
-		active_rx_slots = popcount(ssp->ssp_prm[di].hw_cfg[hwi].rx_slots);
+		active_tx_slots = alpopcount(ssp->ssp_prm[di].hw_cfg[hwi].tx_slots);
+		active_rx_slots = alpopcount(ssp->ssp_prm[di].hw_cfg[hwi].rx_slots);
 
 		/*
 		 * handle TDM mode, TDM mode has padding at the end of
@@ -952,7 +953,8 @@ int ssp_set_params(struct intel_nhlt_par
 	return 0;
 }
 
-int ssp_hw_set_params(struct intel_nhlt_params *nhlt, const char *format, const char *,
+int ssp_hw_set_params(struct intel_nhlt_params *nhlt, const char *format,
+		      const char *mclk ATTRIBUTE_UNUSED,
 		      const char *bclk, const char *bclk_invert, const char *fsync,
 		      const char *fsync_invert, int mclk_freq, int bclk_freq, int fsync_freq,
 		      int tdm_slots, int tdm_slot_width, int tx_slots, int rx_slots)
