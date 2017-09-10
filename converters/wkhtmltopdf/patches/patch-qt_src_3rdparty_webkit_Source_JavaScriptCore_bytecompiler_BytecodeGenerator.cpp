$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_bytecompiler_BytecodeGenerator.cpp,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/3rdparty/webkit/Source/JavaScriptCore/bytecompiler/BytecodeGenerator.cpp.orig	2017-09-09 19:18:57.033156793 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/bytecompiler/BytecodeGenerator.cpp
@@ -2058,9 +2058,9 @@ RegisterID* BytecodeGenerator::emitCatch
 {
     m_usesExceptions = true;
 #if ENABLE(JIT)
-    HandlerInfo info = { start->bind(0, 0), end->bind(0, 0), instructions().size(), m_dynamicScopeDepth + m_baseScopeDepth, CodeLocationLabel() };
+    HandlerInfo info = { (uint32_t)start->bind(0, 0), (uint32_t)end->bind(0, 0), (uint32_t)instructions().size(), (uint32_t)(m_dynamicScopeDepth + m_baseScopeDepth, CodeLocationLabel()) };
 #else
-    HandlerInfo info = { start->bind(0, 0), end->bind(0, 0), instructions().size(), m_dynamicScopeDepth + m_baseScopeDepth };
+    HandlerInfo info = { (uint32_t)start->bind(0, 0), (uint32_t)end->bind(0, 0), (uint32_t)instructions().size(), (uint32_t)(m_dynamicScopeDepth + m_baseScopeDepth) };
 #endif
 
     m_codeBlock->addExceptionHandler(info);
@@ -2107,7 +2107,7 @@ void BytecodeGenerator::emitPushNewScope
 
 void BytecodeGenerator::beginSwitch(RegisterID* scrutineeRegister, SwitchInfo::SwitchType type)
 {
-    SwitchInfo info = { instructions().size(), type };
+    SwitchInfo info = { (uint32_t)instructions().size(), type };
     switch (type) {
         case SwitchInfo::SwitchImmediate:
             emitOpcode(op_switch_imm);
