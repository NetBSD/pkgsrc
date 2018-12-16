$NetBSD: patch-mailnews_compose_src_nsMsgCompose.cpp,v 1.1 2018/12/16 08:29:48 ryoon Exp $

Fix from upstream for Bug 1444371:
mail.label_ascii_only_mail_as_us_ascii does not work with ISO-2022-JP

--- mailnews/compose/src/nsMsgCompose.cpp.orig	2018-03-23 13:59:55.545701174 +0900
+++ mailnews/compose/src/nsMsgCompose.cpp	2018-03-23 14:00:30.158529214 +0900
@@ -1321,12 +1321,11 @@ NS_IMETHODIMP nsMsgCompose::SendMsg(MSG_
   }
   if (!msgBody.IsEmpty())
   {
+    bool isAsciiOnly = NS_IsAscii(static_cast<const char16_t*>(msgBody.get()));
     // Convert body to mail charset
     nsCString outCString;
     rv = nsMsgI18NConvertFromUnicode(m_compFields->GetCharacterSet(),
       msgBody, outCString, false, true);
-    bool isAsciiOnly = NS_IsAscii(outCString.get()) &&
-      !nsMsgI18Nstateful_charset(m_compFields->GetCharacterSet());
     if (m_compFields->GetForceMsgEncoding())
       isAsciiOnly = false;
     if (NS_SUCCEEDED(rv) && !outCString.IsEmpty())
