$NetBSD: patch-netwerk_protocol_http_nsHttpHandler.cpp,v 1.1 2024/10/01 15:01:28 ryoon Exp $

* Do not freeze user-agent string as Linux under NetBSD.

--- netwerk/protocol/http/nsHttpHandler.cpp.orig	2024-03-12 14:30:47.266423256 +0000
+++ netwerk/protocol/http/nsHttpHandler.cpp
@@ -903,6 +903,8 @@ void nsHttpHandler::InitUserAgentCompone
   if (mozilla::StaticPrefs::network_http_useragent_freezeCpu()) {
 #  ifdef ANDROID
     mOscpu.AssignLiteral("Linux armv81");
+#  elif defined(__NetBSD__)
+    mOscpu.AssignLiteral("NetBSD x86_64");
 #  else
     mOscpu.AssignLiteral("Linux x86_64");
 #  endif
