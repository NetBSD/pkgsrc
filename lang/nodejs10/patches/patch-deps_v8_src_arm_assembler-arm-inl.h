$NetBSD: patch-deps_v8_src_arm_assembler-arm-inl.h,v 1.1 2019/12/09 20:05:40 adam Exp $

--- deps/v8/src/arm/assembler-arm-inl.h.orig	2018-12-10 21:19:05.000000000 +0000
+++ deps/v8/src/arm/assembler-arm-inl.h
@@ -386,7 +386,7 @@ void Assembler::set_target_address_at(Ad
            IsOrrImmed(Memory::int32_at(pc + 2 * kInstrSize)) &&
            IsOrrImmed(Memory::int32_at(pc + 3 * kInstrSize)));
     uint32_t* instr_ptr = reinterpret_cast<uint32_t*>(pc);
-    uint32_t immediate = reinterpret_cast<uint32_t>(target);
+    uint32_t immediate = static_cast<uint32_t>(target);
     instr_ptr[0] = PatchShiftImm(instr_ptr[0], immediate & kImm8Mask);
     instr_ptr[1] = PatchShiftImm(instr_ptr[1], immediate & (kImm8Mask << 8));
     instr_ptr[2] = PatchShiftImm(instr_ptr[2], immediate & (kImm8Mask << 16));
