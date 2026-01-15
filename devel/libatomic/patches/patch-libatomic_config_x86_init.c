$NetBSD: patch-libatomic_config_x86_init.c,v 1.1 2026/01/15 11:09:49 wiz Exp $

Fix build when an older gcc's cpuid.h is found.

--- libatomic/config/x86/init.c.orig	2026-01-15 11:08:04.804533308 +0000
+++ libatomic/config/x86/init.c
@@ -49,7 +49,10 @@ __libat_feat1_init (void)
 	  if (ecx2 != signature_INTEL_ecx
 	      && ecx2 != signature_AMD_ecx
 	      && !(ecx2 == signature_CENTAUR_ecx && family > 6)
-	      && ecx2 != signature_SHANGHAI_ecx)
+#ifdef signature_SHANGHAI_ecx
+	      && ecx2 != signature_SHANGHAI_ecx
+#endif
+		)
 	    FEAT1_REGISTER &= ~bit_AVX;
 	}
 #endif
