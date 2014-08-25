$NetBSD: patch-src_lib_server_CClientProxy1__4.cpp,v 1.1 2014/08/25 09:58:18 obache Exp $

--- src/lib/server/CClientProxy1_4.cpp.orig	2013-05-01 15:53:22.000000000 +0000
+++ src/lib/server/CClientProxy1_4.cpp
@@ -102,7 +102,7 @@ CClientProxy1_4::cryptoIv()
 	CString data(reinterpret_cast<const char*>(iv), CRYPTO_IV_SIZE);
 
 	LOG((CLOG_DEBUG2 "send crypto iv change to \"%s\"", getName().c_str()));
-	CProtocolUtil::writef(getStream(), kMsgDCryptoIv, &data);
+	CProtocolUtil::writef(getStream(), kMsgDCryptoIv, "%s", &data);
 	
 	// change IV only after we've sent the current IV, otherwise
 	// the client won't be able to decrypt the new IV.
