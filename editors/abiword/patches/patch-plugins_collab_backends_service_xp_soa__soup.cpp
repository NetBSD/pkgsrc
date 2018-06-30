$NetBSD: patch-plugins_collab_backends_service_xp_soa__soup.cpp,v 1.1 2018/06/30 12:43:29 maya Exp $

Bug 13754 - Fix build on gcc-6 (default to C++11).
https://github.com/AbiWord/abiword/commit/a83e6f50dbd5efa16fb39efe32b9de370f103130

--- plugins/collab/backends/service/xp/soa_soup.cpp.orig	2009-09-29 13:58:11.000000000 +0000
+++ plugins/collab/backends/service/xp/soa_soup.cpp
@@ -163,7 +163,7 @@ namespace soup_soa {
 	
 	static bool _invoke(const std::string& /*url*/, const soa::method_invocation& /*mi*/, SoaSoupSession& sess, std::string& result) {
 		if (!sess.m_session || !sess.m_msg )
-			return soa::GenericPtr();
+			return false;
 
 		guint status = soup_session_send_message (sess.m_session, sess.m_msg);
 		if (!(SOUP_STATUS_IS_SUCCESSFUL (status) ||
