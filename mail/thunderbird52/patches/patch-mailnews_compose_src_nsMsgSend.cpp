$NetBSD: patch-mailnews_compose_src_nsMsgSend.cpp,v 1.1 2018/12/16 08:29:48 ryoon Exp $

Fix from upstream for Bug 1444371:
mail.label_ascii_only_mail_as_us_ascii does not work with ISO-2022-JP

--- mailnews/compose/src/nsMsgSend.cpp.orig	2018-03-23 14:00:40.325824595 +0900
+++ mailnews/compose/src/nsMsgSend.cpp	2018-03-23 14:01:05.961104275 +0900
@@ -1591,9 +1591,8 @@ nsMsgComposeAndSend::GetBodyFromEditor()
 
   if (aCharset && *aCharset)
   {
+    bool isAsciiOnly = NS_IsAscii(bodyText);
     rv = nsMsgI18NConvertFromUnicode(aCharset, nsDependentString(bodyText), outCString, false, true);
-    bool isAsciiOnly = NS_IsAscii(outCString.get()) &&
-      !nsMsgI18Nstateful_charset(mCompFields->GetCharacterSet());
     if (mCompFields->GetForceMsgEncoding())
       isAsciiOnly = false;
     mCompFields->SetBodyIsAsciiOnly(isAsciiOnly);
