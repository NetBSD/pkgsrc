$NetBSD: patch-media_webrtc_trunk_webrtc_modules_video__capture_device__info__impl.cc,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/video_capture/device_info_impl.cc.orig	2013-05-11 19:19:45.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/video_capture/device_info_impl.cc
@@ -54,7 +54,7 @@ WebRtc_Word32 DeviceInfoImpl::NumberOfCa
     if (_lastUsedDeviceNameLength == strlen((char*) deviceUniqueIdUTF8))
     {
         // Is it the same device that is asked for again.
-#if defined(WEBRTC_MAC) || defined(WEBRTC_LINUX)
+#if defined(WEBRTC_MAC) || defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
         if(strncasecmp((char*)_lastUsedDeviceName,
                        (char*) deviceUniqueIdUTF8,
                        _lastUsedDeviceNameLength)==0)
@@ -91,7 +91,7 @@ WebRtc_Word32 DeviceInfoImpl::GetCapabil
     ReadLockScoped cs(_apiLock);
 
     if ((_lastUsedDeviceNameLength != strlen((char*) deviceUniqueIdUTF8))
-#if defined(WEBRTC_MAC) || defined(WEBRTC_LINUX)
+#if defined(WEBRTC_MAC) || defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
         || (strncasecmp((char*)_lastUsedDeviceName,
                         (char*) deviceUniqueIdUTF8,
                         _lastUsedDeviceNameLength)!=0))
@@ -155,7 +155,7 @@ WebRtc_Word32 DeviceInfoImpl::GetBestMat
 
     ReadLockScoped cs(_apiLock);
     if ((_lastUsedDeviceNameLength != strlen((char*) deviceUniqueIdUTF8))
-#if defined(WEBRTC_MAC) || defined(WEBRTC_LINUX)
+#if defined(WEBRTC_MAC) || defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
         || (strncasecmp((char*)_lastUsedDeviceName,
                         (char*) deviceUniqueIdUTF8,
                         _lastUsedDeviceNameLength)!=0))
