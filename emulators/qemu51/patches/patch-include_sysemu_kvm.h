$NetBSD: patch-include_sysemu_kvm.h,v 1.1 2021/02/20 22:55:19 ryoon Exp $

Fix debug build on NetBSD (without Linux-KVM).

--- include/sysemu/kvm.h.orig	2019-12-12 18:20:48.000000000 +0000
+++ include/sysemu/kvm.h
@@ -465,8 +465,16 @@ int kvm_vm_check_extension(KVMState *s, 
         kvm_vcpu_ioctl(cpu, KVM_ENABLE_CAP, &cap);                   \
     })
 
+#ifdef CONFIG_KVM
 uint32_t kvm_arch_get_supported_cpuid(KVMState *env, uint32_t function,
                                       uint32_t index, int reg);
+#else
+#define kvm_arch_get_supported_cpuid(a,b,c,d)                        \
+    ({                                                               \
+        abort();                                                     \
+        0;                                                           \
+    })
+#endif
 uint64_t kvm_arch_get_supported_msr_feature(KVMState *s, uint32_t index);
 
 
