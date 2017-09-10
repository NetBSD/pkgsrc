$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_wtf_text_AtomicString.cpp,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/text/AtomicString.cpp.orig	2017-09-09 19:11:52.085626521 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/text/AtomicString.cpp
@@ -294,7 +294,7 @@ PassRefPtr<StringImpl> AtomicString::add
     if (!s)
         return 0;
 
-    int length = 0;
+    unsigned length = 0;
     while (s[length] != UChar(0))
         length++;
 
