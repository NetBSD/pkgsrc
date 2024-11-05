$NetBSD: patch-yjit_src_asm_arm64_arg_mod.rs,v 1.1 2024/11/05 14:58:03 taca Exp $

* Stop "unused import" warning.

--- yjit/src/asm/arm64/arg/mod.rs.orig	2024-10-30 09:47:11.000000000 +0000
+++ yjit/src/asm/arm64/arg/mod.rs
@@ -10,7 +10,6 @@ mod sys_reg;
 mod truncate;
 
 pub use bitmask_imm::BitmaskImmediate;
-pub use condition::Condition;
 pub use inst_offset::InstructionOffset;
 pub use sf::Sf;
 pub use shifted_imm::ShiftedImmediate;
