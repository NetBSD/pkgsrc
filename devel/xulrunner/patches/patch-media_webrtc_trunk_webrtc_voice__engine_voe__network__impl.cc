$NetBSD: patch-media_webrtc_trunk_webrtc_voice__engine_voe__network__impl.cc,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- media/webrtc/trunk/webrtc/voice_engine/voe_network_impl.cc.orig	2013-05-11 19:19:46.000000000 +0000
+++ media/webrtc/trunk/webrtc/voice_engine/voe_network_impl.cc
@@ -472,7 +472,7 @@ int VoENetworkImpl::SetSendTOS(int chann
                  "SetSendTOS(channel=%d, DSCP=%d, useSetSockopt=%d)",
                  channel, DSCP, useSetSockopt);
 
-#if !defined(_WIN32) && !defined(WEBRTC_LINUX) && !defined(WEBRTC_MAC)
+#if !defined(_WIN32) && !defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD) && !defined(WEBRTC_MAC)
     _shared->SetLastError(VE_FUNC_NOT_SUPPORTED, kTraceWarning,
         "SetSendTOS() is not supported on this platform");
     return -1;
@@ -528,7 +528,7 @@ int VoENetworkImpl::SetSendTOS(int chann
             "SetSendTOS() external transport is enabled");
         return -1;
     }
-#if defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
     useSetSockopt = true;
     WEBRTC_TRACE(kTraceInfo, kTraceVoice, VoEId(_shared->instance_id(), -1),
                  "   force useSetSockopt=true since there is no alternative"
@@ -551,7 +551,7 @@ int VoENetworkImpl::GetSendTOS(int chann
     WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
                  "GetSendTOS(channel=%d)", channel);
 
-#if !defined(_WIN32) && !defined(WEBRTC_LINUX) && !defined(WEBRTC_MAC)
+#if !defined(_WIN32) && !defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD) && !defined(WEBRTC_MAC)
     _shared->SetLastError(VE_FUNC_NOT_SUPPORTED, kTraceWarning,
         "GetSendTOS() is not supported on this platform");
     return -1;
