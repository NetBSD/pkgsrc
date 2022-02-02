$NetBSD: patch-gcc_config_arm_bpabi.h,v 1.1 2022/02/02 22:07:28 mrg Exp $

--- gcc/config/arm/bpabi.h.orig	2021-04-08 04:56:28.061740583 -0700
+++ gcc/config/arm/bpabi.h	2022-01-31 21:13:16.734263818 -0800
@@ -24,6 +24,7 @@
    <http://www.gnu.org/licenses/>.  */
 
 /* Use the AAPCS ABI by default.  */
+#undef ARM_DEFAULT_ABI
 #define ARM_DEFAULT_ABI ARM_ABI_AAPCS
 
 /* Assume that AAPCS ABIs should adhere to the full BPABI.  */
@@ -107,7 +108,9 @@
 /* The BPABI specifies the use of .{init,fini}_array.  Therefore, we
    do not want GCC to put anything into the .{init,fini} sections.  */
 #undef INIT_SECTION_ASM_OP
+#define INIT_SECTION_ASM_OP ""
 #undef FINI_SECTION_ASM_OP
+#define FINI_SECTION_ASM_OP ""
 #define INIT_ARRAY_SECTION_ASM_OP ARM_EABI_CTORS_SECTION_OP
 #define FINI_ARRAY_SECTION_ASM_OP ARM_EABI_DTORS_SECTION_OP
 
