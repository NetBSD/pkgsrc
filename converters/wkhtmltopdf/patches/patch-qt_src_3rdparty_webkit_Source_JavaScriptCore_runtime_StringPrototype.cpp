$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_runtime_StringPrototype.cpp,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/3rdparty/webkit/Source/JavaScriptCore/runtime/StringPrototype.cpp.orig	2017-09-09 19:28:11.632218057 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/runtime/StringPrototype.cpp
@@ -463,7 +463,7 @@ EncodedJSValue JSC_HOST_CALL stringProto
     }
     
     size_t matchEnd = matchPos + matchLen;
-    int ovector[2] = { matchPos, matchEnd };
+    int ovector[2] = { (int)matchPos, (int)matchEnd };
     return JSValue::encode(jsString(exec, source.substringSharingImpl(0, matchPos), substituteBackreferences(replacementString, source, ovector, 0), source.substringSharingImpl(matchEnd)));
 }
 
