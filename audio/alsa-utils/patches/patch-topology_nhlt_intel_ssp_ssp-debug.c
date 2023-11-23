$NetBSD: patch-topology_nhlt_intel_ssp_ssp-debug.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- topology/nhlt/intel/ssp/ssp-debug.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ topology/nhlt/intel/ssp/ssp-debug.c
@@ -7,6 +7,7 @@
 #include "aconfig.h"
 #include <stdio.h>
 #include <stdint.h>
+#include <alsa/global.h>
 #include "ssp-debug.h"
 #include "../intel-nhlt.h"
 
@@ -252,6 +253,6 @@ void ssp_print_internal(struct intel_ssp
 }
 
 #else /* NHLT_DEBUG */
-void ssp_print_internal(struct intel_ssp_params *) {}
-void ssp_print_calculated(struct intel_ssp_params *) {}
+void ssp_print_internal(struct intel_ssp_params *ssp ATTRIBUTE_UNUSED) {}
+void ssp_print_calculated(struct intel_ssp_params *ssp ATTRIBUTE_UNUSED) {}
 #endif
