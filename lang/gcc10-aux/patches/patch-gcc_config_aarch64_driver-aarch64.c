$NetBSD: patch-gcc_config_aarch64_driver-aarch64.c,v 1.1 2022/03/13 08:34:04 nia Exp $

Match what is in NetBSD src.  Fixes at least aarch64eb, and
probably several others.

--- gcc/config/aarch64/driver-aarch64.c.orig	2021-04-08 04:56:28.041740341 -0700
+++ gcc/config/aarch64/driver-aarch64.c	2021-04-24 00:16:45.471750258 -0700
@@ -25,6 +25,7 @@
 #include "system.h"
 #include "coretypes.h"
 #include "tm.h"
+#include "diagnostic-core.h"
 
 /* Defined in common/config/aarch64/aarch64-common.c.  */
 std::string aarch64_get_extension_string_for_isa_flags (uint64_t, uint64_t);
@@ -244,6 +245,14 @@
    ARGC and ARGV are set depending on the actual arguments given
    in the spec.  */
 
+#ifdef __NetBSD__
+/* The NetBSD/arm64 platform may not export linux-style /proc/cpuinfo,
+   but the data is available via a sysctl(3) interface.  */
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <aarch64/armreg.h>
+#endif
+
 const char *
 host_detect_local_cpu (int argc, const char **argv)
 {
@@ -282,6 +291,7 @@
   if (!arch && !tune && !cpu)
     goto not_found;
 
+#ifndef __NetBSD__
   fcpu_info = getenv ("GCC_CPUINFO");
   if (fcpu_info)
     f = fopen (fcpu_info, "r");
@@ -374,6 +384,145 @@
 
   fclose (f);
   f = NULL;
+#else
+  unsigned int curcpu;
+  size_t len;
+  char impl_buf[8];
+  int mib[2], ncpu;
+
+  mib[0] = CTL_HW;
+  mib[1] = HW_NCPU; 
+  len = sizeof(ncpu);
+  if (sysctl(mib, 2, &ncpu, &len, NULL, 0) == -1)
+    goto not_found;
+
+  for (curcpu = 0; curcpu < ncpu; curcpu++)
+    {
+      char path[128];
+      struct aarch64_sysctl_cpu_id id;
+
+      len = sizeof id;
+      snprintf(path, sizeof path, "machdep.cpu%d.cpu_id", curcpu);
+      if (sysctlbyname(path, &id, &len, NULL, 0) != 0)
+        goto not_found;
+
+      unsigned cimp = __SHIFTOUT(id.ac_midr, MIDR_EL1_IMPL);
+      if (cimp == INVALID_IMP)
+        goto not_found;
+
+      if (imp == INVALID_IMP)
+        imp = cimp;
+	/* FIXME: BIG.little implementers are always equal. */
+      else if (imp != cimp)
+        goto not_found;
+  
+      unsigned cvariant = __SHIFTOUT(id.ac_midr, MIDR_EL1_VARIANT);
+      if (!contains_core_p (variants, cvariant))
+        {
+          if (n_variants == 2)
+            goto not_found;
+  
+          variants[n_variants++] = cvariant;
+  	}
+
+      unsigned ccore = __SHIFTOUT(id.ac_midr, MIDR_EL1_PARTNUM);
+      if (!contains_core_p (cores, ccore))
+  	{
+  	  if (n_cores == 2)
+  	    goto not_found;
+  
+  	  cores[n_cores++] = ccore;
+  	}
+
+      if (!tune && !processed_exts)
+        {
+          std::string exts;
+
+	  /* These are all the extensions from aarch64-option-extensions.def.  */
+          if (__SHIFTOUT(id.ac_aa64pfr0, ID_AA64PFR0_EL1_FP) == ID_AA64PFR0_EL1_FP_IMPL)
+	    exts += "fp ";
+          if (__SHIFTOUT(id.ac_aa64pfr0, ID_AA64PFR0_EL1_ADVSIMD) == ID_AA64PFR0_EL1_ADV_SIMD_IMPL)
+	    exts += "asimd ";
+#ifdef ID_AA64ISAR0_EL1_RDM
+          if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_RDM) == ID_AA64ISAR0_EL1_RDM_SQRDML)
+	    exts += "asimdrdm ";
+          if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_DP) == ID_AA64ISAR0_EL1_DP_UDOT)
+	    exts += "asimddp ";
+          if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_FHM) == ID_AA64ISAR0_EL1_FHM_FMLAL)
+	    exts += "asimdfml ";
+#endif
+          if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_AES) == ID_AA64ISAR0_EL1_AES_AES)
+	    exts += "aes ";
+          if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_AES) == ID_AA64ISAR0_EL1_AES_PMUL)
+	    exts += "aes pmull ";
+          if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_CRC32) == ID_AA64ISAR0_EL1_CRC32_CRC32X)
+	    exts += "crc32 ";
+#ifdef ID_AA64ISAR0_EL1_ATOMIC
+          if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_ATOMIC) == ID_AA64ISAR0_EL1_ATOMIC_SWP)
+	    exts += "atomics ";
+#endif
+          if ((__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SHA1) & ID_AA64ISAR0_EL1_SHA1_SHA1CPMHSU) != 0)
+	    exts += "sha1 ";
+          if ((__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SHA2) & ID_AA64ISAR0_EL1_SHA2_SHA256HSU) != 0)
+	    exts += "sha2 ";
+#ifdef ID_AA64ISAR0_EL1_SHA2_SHA512HSU
+          if ((__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SHA2) & ID_AA64ISAR0_EL1_SHA2_SHA512HSU) != 0)
+	    exts += "sha512 ";
+          if ((__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SHA3) & ID_AA64ISAR0_EL1_SHA3_EOR3) != 0)
+	    exts += "sha3 ";
+          if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SM3) == ID_AA64ISAR0_EL1_SM3_SM3)
+	    exts += "sm3 ";
+          if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SM4) == ID_AA64ISAR0_EL1_SM4_SM4)
+	    exts += "sm4 ";
+          if (__SHIFTOUT(id.ac_aa64pfr0, ID_AA64PFR0_EL1_SVE) == ID_AA64PFR0_EL1_SVE_IMPL)
+	    exts += "sve ";
+          if (__SHIFTOUT(id.ac_aa64isar1, ID_AA64ISAR1_EL1_LRCPC) == ID_AA64ISAR1_EL1_LRCPC_PR)
+	    exts += "lrcpc ";
+#endif
+
+          for (i = 0; i < num_exts; i++)
+            {
+	      const char *p = aarch64_extensions[i].feat_string;
+
+	      /* If the feature contains no HWCAPS string then ignore it for the
+		 auto detection.  */
+	      if (*p == '\0')
+		continue;
+
+	      bool enabled = true;
+
+	      /* This may be a multi-token feature string.  We need
+		 to match all parts, which could be in any order.  */
+	      size_t len = strlen (exts.c_str());
+	      do
+		{
+		  const char *end = strchr (p, ' ');
+		  if (end == NULL)
+		    end = strchr (p, '\0');
+		  if (memmem (exts.c_str(), len, p, end - p) == NULL)
+		    {
+		      /* Failed to match this token.  Turn off the
+			 features we'd otherwise enable.  */
+		      enabled = false;
+		      break;
+		    }
+		  if (*end == '\0')
+		    break;
+		  p = end + 1;
+		}
+	      while (1);
+
+              if (enabled)
+                extension_flags |= aarch64_extensions[i].flag;
+              else
+                extension_flags &= ~(aarch64_extensions[i].flag);
+            }
+
+          processed_exts = true;
+	}
+    }
+  /* End of NetBSD specific section.  */
+#endif
 
   /* Weird cpuinfo format that we don't know how to handle.  */
   if (n_cores == 0
