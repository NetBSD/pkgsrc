$NetBSD: patch-topology_nhlt_nhlt-processor.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- topology/nhlt/nhlt-processor.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ topology/nhlt/nhlt-processor.c
@@ -11,6 +11,7 @@
 #include <string.h>
 #include <stdbool.h>
 #include <inttypes.h>
+#include <alsa/global.h>
 #include <alsa/input.h>
 #include <alsa/output.h>
 #include <alsa/conf.h>
@@ -87,7 +88,8 @@ static void debug_print_nhlt(struct nhlt
 	fprintf(stdout, "\n");
 }
 #else
-static void debug_print_nhlt(struct nhlt *, struct endpoint_descriptor **) {}
+static void debug_print_nhlt(struct nhlt *blob ATTRIBUTE_UNUSED,
+			     struct endpoint_descriptor **eps ATTRIBUTE_UNUSED) {}
 #endif
 
 static int print_as_hex_bytes(uint8_t *manifest_buffer, uint32_t manifest_size,
@@ -313,7 +315,8 @@ static int nhlt_get_flat_buffer(struct n
 }
 
 /* called at the end of topology pre-processing, create flat buffer from variable size nhlt */
-static int nhlt_create(struct intel_nhlt_params *nhlt, snd_config_t *input, snd_config_t *,
+static int nhlt_create(struct intel_nhlt_params *nhlt, snd_config_t *input,
+		       snd_config_t *output ATTRIBUTE_UNUSED,
 		       uint8_t **nhlt_buffer, uint32_t *nhlt_size)
 {
 	struct endpoint_descriptor *eps[MAX_ENDPOINT_COUNT];
