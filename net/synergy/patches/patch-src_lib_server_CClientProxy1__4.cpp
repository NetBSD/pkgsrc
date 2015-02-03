$NetBSD: patch-src_lib_server_CClientProxy1__4.cpp,v 1.2 2015/02/03 18:49:34 tnn Exp $

g++ on sparc64 complains: ISO C++ says that these are ambiguous:
synergy/ProtocolUtil.h:82:16: note: candidate 1: static void ProtocolUtil::writef(void*, const char*, va_list)
  static void   writef(void*, const char* fmt, va_list);
                ^
synergy/ProtocolUtil.h:53:16: note: candidate 2: static void ProtocolUtil::writef(synergy::IStream*, const char*, ...)
  static void   writef(synergy::IStream*,
                ^
synergy/ProtocolUtil.h:82:16: error: 'static void ProtocolUtil::writef(void*, const char*, va_list)' is private
  static void   writef(void*, const char* fmt, va_list);

--- src/lib/server/ClientProxy1_4.cpp.orig	2014-12-02 15:03:19.000000000 +0000
+++ src/lib/server/ClientProxy1_4.cpp
@@ -83,7 +83,7 @@ ClientProxy1_4::cryptoIv()
 	String data(reinterpret_cast<const char*>(iv), CRYPTO_IV_SIZE);
 
 	LOG((CLOG_DEBUG2 "send crypto iv change to \"%s\"", getName().c_str()));
-	ProtocolUtil::writef(getStream(), kMsgDCryptoIv, &data);
+	ProtocolUtil::writef(getStream(), kMsgDCryptoIv, "%s", &data);
 	
 	// change IV only after we've sent the current IV, otherwise
 	// the client won't be able to decrypt the new IV.
