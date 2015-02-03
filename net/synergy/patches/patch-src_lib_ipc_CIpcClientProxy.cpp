$NetBSD: patch-src_lib_ipc_CIpcClientProxy.cpp,v 1.2 2015/02/03 18:49:34 tnn Exp $

g++ on sparc64 complains: ISO C++ says that these are ambiguous:
synergy/ProtocolUtil.h:82:16: note: candidate 1: static void ProtocolUtil::writef(void*, const char*, va_list)
  static void   writef(void*, const char* fmt, va_list);
                ^
synergy/ProtocolUtil.h:53:16: note: candidate 2: static void ProtocolUtil::writef(synergy::IStream*, const char*, ...)
  static void   writef(synergy::IStream*,
                ^
synergy/ProtocolUtil.h:82:16: error: 'static void ProtocolUtil::writef(void*, const char*, va_list)' is private
  static void   writef(void*, const char* fmt, va_list);
                ^
--- src/lib/ipc/IpcClientProxy.cpp.orig	2014-12-02 15:03:19.000000000 +0000
+++ src/lib/ipc/IpcClientProxy.cpp
@@ -147,7 +147,7 @@ IpcClientProxy::send(const IpcMessage& m
 	case kIpcLogLine: {
 		const IpcLogLineMessage& llm = static_cast<const IpcLogLineMessage&>(message);
 		String logLine = llm.logLine();
-		ProtocolUtil::writef(&m_stream, kIpcMsgLogLine, &logLine);
+		ProtocolUtil::writef(&m_stream, kIpcMsgLogLine, "%s", &logLine);
 		break;
 	}
 			
