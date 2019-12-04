$NetBSD: patch-src_hotspot_os__cpu_bsd__aarch64_os__bsd__aarch64.cpp,v 1.1 2019/12/04 12:19:25 tnn Exp $

NetBSD/evbarm-aarch64 support

--- src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp.orig	2019-10-16 18:31:09.000000000 +0000
+++ src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp
@@ -103,6 +103,8 @@ address os::Bsd::ucontext_get_pc(const u
   return (address)uc->uc_mcontext.mc_gpregs.gp_elr;
 #elif defined(__OpenBSD__)
   return (address)uc->sc_elr;
+#elif defined(__NetBSD__)
+  return (address)uc->uc_mcontext.__gregs[_REG_ELR];
 #endif
 }
 
@@ -111,6 +113,8 @@ void os::Bsd::ucontext_set_pc(ucontext_t
   uc->uc_mcontext.mc_gpregs.gp_elr = (intptr_t)pc;
 #elif defined(__OpenBSD__)
   uc->sc_elr = (unsigned long)pc;
+#elif defined(__NetBSD__)
+  uc->uc_mcontext.__gregs[_REG_ELR] = (__greg_t)pc;
 #endif
 }
 
@@ -119,6 +123,8 @@ intptr_t* os::Bsd::ucontext_get_sp(const
   return (intptr_t*)uc->uc_mcontext.mc_gpregs.gp_sp;
 #elif defined(__OpenBSD__)
   return (intptr_t*)uc->sc_sp;
+#elif defined(__NetBSD__)
+  return (intptr_t*)uc->uc_mcontext.__gregs[_REG_SP];
 #endif
 }
 
@@ -127,6 +133,8 @@ intptr_t* os::Bsd::ucontext_get_fp(const
   return (intptr_t*)uc->uc_mcontext.mc_gpregs.gp_x[REG_FP];
 #elif defined(__OpenBSD__)
   return (intptr_t*)uc->sc_x[REG_FP];
+#elif defined(__NetBSD__)
+  return (intptr_t*)uc->uc_mcontext.__gregs[_REG_FP];
 #endif
 }
 
@@ -204,6 +212,9 @@ bool os::Bsd::get_frame_at_stack_banging
 #elif defined(__OpenBSD__)
       address pc = (address)(uc->sc_lr
                          - NativeInstruction::instruction_size);
+#elif defined(__NetBSD__)
+      address pc = (address)(uc->uc_mcontext.__gregs[_REG_LR]
+                         - NativeInstruction::instruction_size);
 #endif
       *fr = frame(sp, fp, pc);
       if (!fr->is_java_frame()) {
@@ -552,6 +563,8 @@ void os::print_context(outputStream *st,
     print_location(st, uc->uc_mcontext.mc_gpregs.gp_x[r]);
 #elif defined(__OpenBSD__)
     print_location(st, uc->sc_x[r]);
+#elif defined(__NetBSD__)
+    print_location(st, uc->uc_mcontext.__gregs[r]);
 #endif
   }
   st->cr();
@@ -588,6 +601,8 @@ void os::print_register_info(outputStrea
     st->print_cr(  "R%d=" INTPTR_FORMAT, r, (uintptr_t)uc->uc_mcontext.mc_gpregs.gp_x[r]);
 #elif defined(__OpenBSD__)
     st->print_cr(  "R%d=" INTPTR_FORMAT, r, (uintptr_t)uc->sc_x[r]);
+#elif defined(__NetBSD__)
+    st->print_cr(  "R%d=" INTPTR_FORMAT, r, (uintptr_t)uc->uc_mcontext.__gregs[r]);
 #endif
   st->cr();
 }
