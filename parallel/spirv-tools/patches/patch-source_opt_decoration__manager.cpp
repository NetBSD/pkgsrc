$NetBSD: patch-source_opt_decoration__manager.cpp,v 1.1 2026/04/08 11:33:52 tnn Exp $

GCC 16 issue
https://github.com/KhronosGroup/SPIRV-Tools/commit/c28f5937bce369dde1d645299a8c9873da43dc72.patch

--- source/opt/decoration_manager.cpp.orig	2025-11-19 18:50:43.000000000 +0000
+++ source/opt/decoration_manager.cpp
@@ -543,7 +543,8 @@ void DecorationManager::CloneDecorations
         const uint32_t num_operands = inst->NumOperands();
         for (uint32_t i = 1; i < num_operands; i += 2) {
           Operand op = inst->GetOperand(i);
-          if (op.words[0] == from) {  // add new pair of operands: (to, literal)
+          if (!op.words.empty() &&
+              op.words[0] == from) {  // add new pair of operands: (to, literal)
             inst->AddOperand(
                 Operand(spv_operand_type_t::SPV_OPERAND_TYPE_ID, {to}));
             op = inst->GetOperand(i + 1);
