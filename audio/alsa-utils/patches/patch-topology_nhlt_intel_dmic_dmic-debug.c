$NetBSD: patch-topology_nhlt_intel_dmic_dmic-debug.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- topology/nhlt/intel/dmic/dmic-debug.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ topology/nhlt/intel/dmic/dmic-debug.c
@@ -8,6 +8,7 @@
 #include "aconfig.h"
 #include <stdio.h>
 #include <stdint.h>
+#include <alsa/global.h>
 #include "dmic-debug.h"
 
 #ifdef NHLT_DEBUG
@@ -181,7 +182,7 @@ void dmic_print_internal(struct intel_dm
 }
 
 #else /* NHLT_DEBUG */
-void dmic_print_bytes_as_hex(uint8_t *, size_t) {}
-void dmic_print_integers_as_hex(uint32_t *, size_t) {}
-void dmic_print_internal(struct intel_dmic_params *) {}
+void dmic_print_bytes_as_hex(uint8_t *src ATTRIBUTE_UNUSED, size_t size ATTRIBUTE_UNUSED) {}
+void dmic_print_integers_as_hex(uint32_t *src ATTRIBUTE_UNUSED, size_t size ATTRIBUTE_UNUSED) {}
+void dmic_print_internal(struct intel_dmic_params *dmic ATTRIBUTE_UNUSED) {}
 #endif
