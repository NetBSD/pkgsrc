$NetBSD: patch-js_src_jit_x86-shared_Constants-x86-shared.h,v 1.1 2020/03/16 13:30:57 tnn Exp $

Since invalid_reg is a valid value for enum RegisterID, it must also
be acceptable to call GPRegName64 with invalid_reg as input, otherwise
GCC stupidly thinks we may pass null as a format string argument:

js/src/jit/x64/BaseAssembler-x64.h:596:13: error: '%s' directive argument
 is null [-Werror=format-overflow=]
596: spew("movq       " MEM_obs ", %s", ADDR_obs(offset, base, index, scale), GPReg64Name(dst));

--- js/src/jit/x86-shared/Constants-x86-shared.h.orig	2018-04-28 01:04:03.000000000 +0000
+++ js/src/jit/x86-shared/Constants-x86-shared.h
@@ -61,6 +61,7 @@ inline const char* GPReg64Name(RegisterI
 #ifdef JS_CODEGEN_X64
        ,"%r8", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15"
 #endif
+	, "invalid_reg"
     };
     MOZ_ASSERT(size_t(reg) < mozilla::ArrayLength(names));
     return names[reg];
