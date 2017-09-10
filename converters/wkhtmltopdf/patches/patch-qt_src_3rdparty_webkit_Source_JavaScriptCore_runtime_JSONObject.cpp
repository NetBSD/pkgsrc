$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_runtime_JSONObject.cpp,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/3rdparty/webkit/Source/JavaScriptCore/runtime/JSONObject.cpp.orig	2017-09-09 19:17:09.419224855 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/runtime/JSONObject.cpp
@@ -335,7 +335,7 @@ void Stringifier::appendQuotedString(USt
             default:
                 static const char hexDigits[] = "0123456789abcdef";
                 UChar ch = data[i];
-                UChar hex[] = { '\\', 'u', hexDigits[(ch >> 12) & 0xF], hexDigits[(ch >> 8) & 0xF], hexDigits[(ch >> 4) & 0xF], hexDigits[ch & 0xF] };
+                UChar hex[] = { '\\', 'u', (UChar)hexDigits[(ch >> 12) & 0xF], (UChar)hexDigits[(ch >> 8) & 0xF], (UChar)hexDigits[(ch >> 4) & 0xF], (UChar)hexDigits[ch & 0xF] };
                 builder.append(hex, WTF_ARRAY_LENGTH(hex));
                 break;
         }
