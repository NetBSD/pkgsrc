$NetBSD: patch-src_hotspot_cpu_aarch64_macroAssembler__aarch64.cpp,v 1.1 2026/09/26 12:54:51 tnn Exp $

GCC 7 (on NetBSD 9) complains:

macroAssembler_aarch64.cpp: In member function 'void MacroAssembler::clinit_barrier(Register, Register, Label*, Label*)':
macroAssembler_aarch64.cpp:2048:48: error: call of overloaded 'cmp(Register&, InstanceKlass::ClassState)' is ambiguous
cmp(scratch, InstanceKlass::fully_initialized);
macroAssembler_aarch64.hpp:204:15: note: candidate: void MacroAssembler::cmp(Register, unsigned char)
inline void cmp(Register Rd, unsigned char imm8)  { subs(zr, Rd, imm8); }
macroAssembler_aarch64.hpp:205:15: note: candidate: void MacroAssembler::cmp(Register, unsigned int) <deleted>
inline void cmp(Register Rd, unsigned imm) = delete;

GCC 7 is not supported by OpenJDK 25 but it's an easy fix so why not.

--- src/hotspot/cpu/aarch64/macroAssembler_aarch64.cpp.orig	2026-09-05 19:06:13.774758654 +0000
+++ src/hotspot/cpu/aarch64/macroAssembler_aarch64.cpp
@@ -2045,7 +2045,7 @@ void MacroAssembler::clinit_barrier(Register klass, Re
   // Fast path check: class is fully initialized
   lea(scratch, Address(klass, InstanceKlass::init_state_offset()));
   ldarb(scratch, scratch);
-  cmp(scratch, InstanceKlass::fully_initialized);
+  cmp(scratch, (unsigned char)InstanceKlass::fully_initialized);
   br(Assembler::EQ, *L_fast_path);
 
   // Fast path check: current thread is initializer thread
