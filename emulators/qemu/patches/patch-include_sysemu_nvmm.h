$NetBSD: patch-include_sysemu_nvmm.h,v 1.5 2021/08/27 03:32:37 ryoon Exp $

* Do not use CONFIG_NVMM directly to avoid pragma poison error.

--- include/sysemu/nvmm.h.orig	2021-08-04 16:29:07.000000000 +0000
+++ include/sysemu/nvmm.h
@@ -13,14 +13,22 @@
 #include "config-host.h"
 #include "qemu-common.h"
 
-#ifdef CONFIG_NVMM
+#ifdef NEED_CPU_H
+# ifdef CONFIG_NVMM
+#  define CONFIG_NVMM_IS_POSSIBLE
+# endif
+#else
+# define CONFIG_NVMM_IS_POSSIBLE
+#endif
+
+#ifdef CONFIG_NVMM_IS_POSSIBLE
 
 int nvmm_enabled(void);
 
-#else /* CONFIG_NVMM */
+#else /* CONFIG_NVMM_IS_POSSIBLE */
 
 #define nvmm_enabled() (0)
 
-#endif /* CONFIG_NVMM */
+#endif /* CONFIG_NVMM_IS_POSSIBLE */
 
-#endif /* CONFIG_NVMM */
+#endif /* QEMU_NVMM_H */
