$NetBSD: patch-common.c,v 1.1 2024/09/13 18:02:45 jschauma Exp $

From https://github.com/open-quantum-safe/liboqs/pull/1876

--- src/common/common.c.orig	2024-06-07 14:38:26.000000000 +0000
+++ src/common/common.c	2024-09-10 04:14:27.028014167 +0000
@@ -141,6 +141,51 @@
 	}
 #endif
 }
+#elif defined(__NetBSD__) || defined(__NetBSD)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <aarch64/armreg.h>
+
+static void set_available_cpu_extensions(void) {
+	/* mark that this function has been called */
+	cpu_ext_data[OQS_CPU_EXT_INIT] = 1;
+	unsigned int cpu = 0;
+	size_t len;
+	char impl_buf[8];
+	int mib[2], ncpu;
+
+	mib[0] = CTL_HW;
+	mib[1] = HW_NCPU;
+	len = sizeof(ncpu);
+	if (sysctl(mib, 2, &ncpu, &len, NULL, 0) != 0) {
+		fprintf(stderr, "Error getting HWCAP for ARM on NetBSD\n");
+		return;
+	}
+
+	char path[128];
+	struct aarch64_sysctl_cpu_id id;
+
+	len = sizeof(id);
+	snprintf(path, sizeof(path), "machdep.cpu%d.cpu_id", cpu);
+	if (sysctlbyname(path, &id, &len, NULL, 0) != 0) {
+		fprintf(stderr, "Error getting HWCAP for ARM on NetBSD\n");
+		return;
+	}
+
+	/* extensions from aarch64-option-extensions.def */
+	if (__SHIFTOUT(id.ac_aa64pfr0, ID_AA64PFR0_EL1_ADVSIMD) == ID_AA64PFR0_EL1_ADV_SIMD_IMPL) {
+		cpu_ext_data[OQS_CPU_EXT_ARM_NEON] = 1;
+	}
+	if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_AES) == ID_AA64ISAR0_EL1_AES_AES) {
+		cpu_ext_data[OQS_CPU_EXT_ARM_AES] = 1;
+	}
+	if ((__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SHA2) & ID_AA64ISAR0_EL1_SHA2_SHA256HSU) != 0) {
+		cpu_ext_data[OQS_CPU_EXT_ARM_SHA2] = 1;
+	}
+	if ((__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SHA3) & ID_AA64ISAR0_EL1_SHA3_EOR3) != 0) {
+		cpu_ext_data[OQS_CPU_EXT_ARM_SHA3] = 1;
+	}
+}
 #elif defined(_WIN32)
 static void set_available_cpu_extensions(void) {
 	/* mark that this function has been called */
