$NetBSD: patch-target_i386_kvm-stub.c,v 1.1 2019/02/13 05:16:12 kamil Exp $

Fix debug build on NetBSD (without Linux-KVM).

--- target/i386/kvm-stub.c.orig	2019-02-02 13:12:09.564671574 +0000
+++ target/i386/kvm-stub.c
@@ -29,16 +29,6 @@ bool kvm_enable_x2apic(void)
 {
     return false;
 }
-
-/* This function is only called inside conditionals which we
- * rely on the compiler to optimize out when CONFIG_KVM is not
- * defined.
- */
-uint32_t kvm_arch_get_supported_cpuid(KVMState *env, uint32_t function,
-                                      uint32_t index, int reg)
-{
-    abort();
-}
 #endif
 
 bool kvm_hv_vpindex_settable(void)
