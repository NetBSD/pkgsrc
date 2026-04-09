--- gcc/config/rs6000/rs6000.cc.orig	2024-06-20 01:08:06.000000000 -0700
+++ gcc/config/rs6000/rs6000.cc	2024-12-17 15:46:35.810029314 -0800
@@ -97,7 +97,8 @@
      of the include files, so that POWERPC_LINUX and POWERPC_FREEBSD are
      properly defined.  */
 #ifndef TARGET_IEEEQUAD_DEFAULT
-#if !defined (POWERPC_LINUX) && !defined (POWERPC_FREEBSD)
+#if !defined (POWERPC_LINUX) && !defined (POWERPC_FREEBSD) \
+    && !defined(POWERPC_NETBSD)
 #define TARGET_IEEEQUAD_DEFAULT 1
 #else
 #define TARGET_IEEEQUAD_DEFAULT 0
@@ -20747,7 +20748,11 @@
   if (flag_pic)
     return 3;
   else if (DEFAULT_ABI == ABI_AIX || DEFAULT_ABI == ABI_ELFv2)
+#if defined (POWERPC_NETBSD)
+    return 3;
+#else
     return 2;
+#endif
   else
     return 0;
 }
