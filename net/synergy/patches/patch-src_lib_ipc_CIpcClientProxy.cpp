$NetBSD: patch-src_lib_ipc_CIpcClientProxy.cpp,v 1.1 2014/08/25 09:58:18 obache Exp $

--- src/lib/ipc/CIpcClientProxy.cpp.orig	2012-09-04 02:09:56.000000000 +0000
+++ src/lib/ipc/CIpcClientProxy.cpp
@@ -144,7 +144,7 @@ CIpcClientProxy::send(const CIpcMessage&
 	case kIpcLogLine: {
 		const CIpcLogLineMessage& llm = static_cast<const CIpcLogLineMessage&>(message);
 		CString logLine = llm.logLine();
-		CProtocolUtil::writef(&m_stream, kIpcMsgLogLine, &logLine);
+		CProtocolUtil::writef(&m_stream, kIpcMsgLogLine, "%s", &logLine);
 		break;
 	}
 			
