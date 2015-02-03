$NetBSD: patch-src_lib_ipc_CIpcServerProxy.cpp,v 1.2 2015/02/03 18:49:34 tnn Exp $

g++ on sparc64 complains: ISO C++ says that these are ambiguous:
synergy/ProtocolUtil.h:82:16: note: candidate 1: static void ProtocolUtil::writef(void*, const char*, va_list)
  static void   writef(void*, const char* fmt, va_list);
                ^
synergy/ProtocolUtil.h:53:16: note: candidate 2: static void ProtocolUtil::writef(synergy::IStream*, const char*, ...)
  static void   writef(synergy::IStream*,
                ^
synergy/ProtocolUtil.h:82:16: error: 'static void ProtocolUtil::writef(void*, const char*, va_list)' is private
  static void   writef(void*, const char* fmt, va_list);

--- src/lib/ipc/IpcServerProxy.cpp.orig	2014-12-02 15:03:19.000000000 +0000
+++ src/lib/ipc/IpcServerProxy.cpp
@@ -95,7 +95,7 @@ IpcServerProxy::send(const IpcMessage& m
 	case kIpcCommand: {
 		const IpcCommandMessage& cm = static_cast<const IpcCommandMessage&>(message);
 		String command = cm.command();
-		ProtocolUtil::writef(&m_stream, kIpcMsgCommand, &command);
+		ProtocolUtil::writef(&m_stream, kIpcMsgCommand, "%s", &command);
 		break;
 	}
 
