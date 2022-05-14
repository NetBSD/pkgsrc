$NetBSD: patch-src_hotspot_os__cpu_bsd__aarch64_os__bsd__aarch64.cpp,v 1.1 2022/05/14 15:23:02 tnn Exp $

NetBSD/evbarm support

--- src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp.orig	2022-04-23 02:25:56.000000000 +0000
+++ src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp
@@ -658,6 +658,8 @@ address os::Posix::ucontext_get_pc(const
   return (address)uc->uc_mcontext.mc_gpregs.gp_elr;
 #elif defined(__OpenBSD__)
   return (address)uc->sc_elr;
+#elif defined(__NetBSD__)
+  return (address)uc->uc_mcontext.__gregs[_REG_ELR];
 #endif
 }
 
@@ -666,6 +668,8 @@ void os::Posix::ucontext_set_pc(ucontext
   uc->uc_mcontext.mc_gpregs.gp_elr = (intptr_t)pc;
 #elif defined(__OpenBSD__)
   uc->sc_elr = (unsigned long)pc;
+#elif defined(__NetBSD__)
+  uc->uc_mcontext.__gregs[_REG_ELR] = (__greg_t)pc;
 #endif
 }
 
@@ -674,6 +678,8 @@ intptr_t* os::Bsd::ucontext_get_sp(const
   return (intptr_t*)uc->uc_mcontext.mc_gpregs.gp_sp;
 #elif defined(__OpenBSD__)
   return (intptr_t*)uc->sc_sp;
+#elif defined(__NetBSD__)
+  return (intptr_t*)uc->uc_mcontext.__gregs[_REG_SP];
 #endif
 }
 
@@ -682,6 +688,8 @@ intptr_t* os::Bsd::ucontext_get_fp(const
   return (intptr_t*)uc->uc_mcontext.mc_gpregs.gp_x[REG_FP];
 #elif defined(__OpenBSD__)
   return (intptr_t*)uc->sc_x[REG_FP];
+#elif defined(__NetBSD__)
+  return (intptr_t*)uc->uc_mcontext.__gregs[_REG_FP];
 #endif
 }
 
@@ -724,6 +732,9 @@ frame os::fetch_compiled_frame_from_cont
 #elif defined(__OpenBSD__)
       address pc = (address)(uc->sc_lr
                          - NativeInstruction::instruction_size);
+#elif defined(__NetBSD__)
+      address pc = (address)(uc->uc_mcontext.__gregs[_REG_LR]
+                         - NativeInstruction::instruction_size);
 #endif
   return frame(sp, fp, pc);
 }
@@ -954,6 +965,8 @@ void os::print_context(outputStream *st,
     print_location(st, uc->uc_mcontext.mc_gpregs.gp_x[r]);
 #elif defined(__OpenBSD__)
     print_location(st, uc->sc_x[r]);
+#elif defined(__NetBSD__)
+    print_location(st, uc->uc_mcontext.__gregs[r]);
 #endif
   }
   st->cr();
@@ -990,6 +1003,8 @@ void os::print_register_info(outputStrea
     st->print_cr(  "R%d=" INTPTR_FORMAT, r, (uintptr_t)uc->uc_mcontext.mc_gpregs.gp_x[r]);
 #elif defined(__OpenBSD__)
     st->print_cr(  "R%d=" INTPTR_FORMAT, r, (uintptr_t)uc->sc_x[r]);
+#elif defined(__NetBSD__)
+    st->print_cr(  "R%d=" INTPTR_FORMAT, r, (uintptr_t)uc->uc_mcontext.__gregs[r]);
 #endif
   st->cr();
 }
