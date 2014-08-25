$NetBSD: patch-src_lib_ipc_CIpcServerProxy.cpp,v 1.1 2014/08/25 09:58:18 obache Exp $

--- src/lib/ipc/CIpcServerProxy.cpp.orig	2012-09-04 02:09:56.000000000 +0000
+++ src/lib/ipc/CIpcServerProxy.cpp
@@ -91,7 +91,7 @@ CIpcServerProxy::send(const CIpcMessage&
 	case kIpcCommand: {
 		const CIpcCommandMessage& cm = static_cast<const CIpcCommandMessage&>(message);
 		CString command = cm.command();
-		CProtocolUtil::writef(&m_stream, kIpcMsgCommand, &command);
+		CProtocolUtil::writef(&m_stream, kIpcMsgCommand, "%s", &command);
 		break;
 	}
 
