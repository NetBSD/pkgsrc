$NetBSD: patch-languages_cpp_codegen_adaptsignatureassistant.cpp,v 1.1 2014/11/21 22:16:55 joerg Exp $

--- languages/cpp/codegen/adaptsignatureassistant.cpp.orig	2014-11-18 09:27:07.000000000 +0000
+++ languages/cpp/codegen/adaptsignatureassistant.cpp
@@ -94,7 +94,7 @@ void AdaptSignatureAssistant::reset()
   m_otherSideId = {};
   m_otherSideTopContext = {};
   m_otherSideContext = {};
-  m_oldSignature = {};
+  m_oldSignature = Cpp::Signature();
   m_document = {};
   m_view.clear();
 }
