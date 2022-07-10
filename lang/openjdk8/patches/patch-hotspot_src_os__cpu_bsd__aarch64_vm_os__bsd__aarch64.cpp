$NetBSD: patch-hotspot_src_os__cpu_bsd__aarch64_vm_os__bsd__aarch64.cpp,v 1.2 2022/07/10 14:47:24 ryoon Exp $

NetBSD/evbarm-aarch64 support

--- hotspot/src/os_cpu/bsd_aarch64/vm/os_bsd_aarch64.cpp.orig	2022-04-23 02:23:55.000000000 +0000
+++ hotspot/src/os_cpu/bsd_aarch64/vm/os_bsd_aarch64.cpp
@@ -110,6 +110,8 @@ address os::Bsd::ucontext_get_pc(ucontex
   return (address)uc->uc_mcontext.mc_gpregs.gp_elr;
 #elif defined(__OpenBSD__)
   return (address)uc->sc_elr;
+#elif defined(__NetBSD__)
+  return (address)uc->uc_mcontext.__gregs[_REG_ELR];
 #endif
 }
 
@@ -118,6 +120,8 @@ void os::Bsd::ucontext_set_pc(ucontext_t
   uc->uc_mcontext.mc_gpregs.gp_elr = (intptr_t)pc;
 #elif defined(__OpenBSD__)
   uc->sc_elr = (unsigned long)pc;
+#elif defined(__NetBSD__)
+  uc->uc_mcontext.__gregs[_REG_ELR] = (__greg_t)pc;
 #endif
 }
 
@@ -126,6 +130,8 @@ intptr_t* os::Bsd::ucontext_get_sp(ucont
   return (intptr_t*)uc->uc_mcontext.mc_gpregs.gp_sp;
 #elif defined(__OpenBSD__)
   return (intptr_t*)uc->sc_sp;
+#elif defined(__NetBSD__)
+  return (intptr_t*)uc->uc_mcontext.__gregs[_REG_SP];
 #endif
 }
 
@@ -134,6 +140,8 @@ intptr_t* os::Bsd::ucontext_get_fp(ucont
   return (intptr_t*)uc->uc_mcontext.mc_gpregs.gp_x[REG_FP];
 #elif defined(__OpenBSD__)
   return (intptr_t*)uc->sc_x[REG_FP];
+#elif defined(__NetBSD__)
+  return (intptr_t*)uc->uc_mcontext.__gregs[_REG_FP];
 #endif
 }
 
