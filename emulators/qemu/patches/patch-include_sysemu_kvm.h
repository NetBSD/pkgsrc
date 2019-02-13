$NetBSD: patch-include_sysemu_kvm.h,v 1.1 2019/02/13 05:16:12 kamil Exp $

Fix debug build on NetBSD (without Linux-KVM).

--- include/sysemu/kvm.h.orig	2019-02-02 13:14:03.877852089 +0000
+++ include/sysemu/kvm.h
@@ -459,8 +459,16 @@ int kvm_vm_check_extension(KVMState *s, 
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
 uint32_t kvm_arch_get_supported_msr_feature(KVMState *s, uint32_t index);
 
 
