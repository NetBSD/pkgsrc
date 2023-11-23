$NetBSD: patch-topology_nhlt_intel_dmic-nhlt.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- topology/nhlt/intel/dmic-nhlt.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ topology/nhlt/intel/dmic-nhlt.c
@@ -10,6 +10,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <alsa/global.h>
 #include <alsa/input.h>
 #include <alsa/output.h>
 #include <alsa/conf.h>
@@ -155,7 +156,7 @@ static int set_vendor_mic_data(struct in
 				   horizontal_angle_end);
 }
 
-static int set_bytes_data(struct intel_nhlt_params *, snd_config_t *cfg)
+static int set_bytes_data(struct intel_nhlt_params *nhlt ATTRIBUTE_UNUSED, snd_config_t *cfg)
 {
 	snd_config_iterator_t i, next;
 	snd_config_t *n;
