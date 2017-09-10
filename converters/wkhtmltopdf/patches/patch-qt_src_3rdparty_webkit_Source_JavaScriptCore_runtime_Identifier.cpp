$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_runtime_Identifier.cpp,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/3rdparty/webkit/Source/JavaScriptCore/runtime/Identifier.cpp.orig	2017-09-09 19:16:30.554645837 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/runtime/Identifier.cpp
@@ -222,7 +222,7 @@ PassRefPtr<StringImpl> Identifier::add(J
     }
     if (!length)
         return StringImpl::empty();
-    UCharBuffer buf = {s, length}; 
+    UCharBuffer buf = {s, (unsigned)length}; 
     pair<HashSet<StringImpl*>::iterator, bool> addResult = globalData->identifierTable->add<UCharBuffer, IdentifierUCharBufferTranslator>(buf);
 
     // If the string is newly-translated, then we need to adopt it.
