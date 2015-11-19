$NetBSD: patch-xbmc_cores_AudioEngine_Sinks_AESinkOSS.cpp,v 1.2 2015/11/19 02:31:47 jmcneill Exp $

--- xbmc/cores/AudioEngine/Sinks/AESinkOSS.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/cores/AudioEngine/Sinks/AESinkOSS.cpp
@@ -32,6 +32,9 @@
 
 #if defined(OSS4) || defined(TARGET_FREEBSD)
   #include <sys/soundcard.h>
+#elif defined(TARGET_NETBSD)
+  #include <sys/soundcard.h>
+  #include <sys/audioio.h>
 #else
   #include <linux/soundcard.h>
 #endif
@@ -41,7 +44,7 @@
 static enum AEChannel OSSChannelMap[9] =
   {AE_CH_FL, AE_CH_FR, AE_CH_BL, AE_CH_BR, AE_CH_FC, AE_CH_LFE, AE_CH_SL, AE_CH_SR, AE_CH_NULL};
 
-#if defined(SNDCTL_SYSINFO) && defined(SNDCTL_CARDINFO)
+#if defined(SNDCTL_SYSINFO) && (defined(SNDCTL_CARDINFO) || defined(TARGET_NETBSD))
 static int OSSSampleRateList[] =
 {
   5512,
@@ -84,6 +87,9 @@ std::string CAESinkOSS::GetDeviceUse(con
 
   if (device.find_first_of('/') != 0)
     return "/dev/dsp_multich";
+#elif defined(TARGET_NETBSD)
+  if (device.find_first_of('/') != 0)
+    return "/dev/sound";
 #else
   if (device.find_first_of('/') != 0)
     return "/dev/dsp";
@@ -422,6 +428,65 @@ void CAESinkOSS::Drain()
 
 void CAESinkOSS::EnumerateDevicesEx(AEDeviceInfoList &list, bool force)
 {
+#if defined(TARGET_NETBSD)
+  for (int i = 0; i < 32; i++)
+  {
+    std::stringstream audioctlpath;
+    std::stringstream devicepath;
+    std::stringstream devicename;
+    CAEDeviceInfo info;
+    audio_device_t adev;
+
+    audioctlpath << "/dev/audioctl" << i;
+    int audioctlfd = open(audioctlpath.str().c_str(), O_RDONLY, 0);
+    if (audioctlfd == -1)
+    {
+      if (errno == ENOENT)
+        break;
+      else
+        continue;
+    }
+
+    if (ioctl(audioctlfd, AUDIO_GETDEV, &adev) == -1)
+    {
+      close(audioctlfd);
+      continue;
+    }
+
+    devicepath << "/dev/sound" << i;
+    info.m_deviceName = devicepath.str();
+    devicename << adev.name;
+    if (strlen(adev.version) > 0)
+      devicename << " " << adev.version;
+    info.m_displayName = devicename.str();
+
+    info.m_dataFormats.push_back(AE_FMT_S16NE);
+    info.m_deviceType = AE_DEVTYPE_PCM;
+
+    oss_audioinfo ainfo;
+    memset(&ainfo, 0, sizeof(ainfo));
+    ainfo.dev = i;
+    if (ioctl(audioctlfd, SNDCTL_AUDIOINFO, &ainfo) != -1) {
+#if 0
+      if (ainfo.oformats & AFMT_S32_LE)
+        info.m_dataFormats.push_back(AE_FMT_S32LE);
+      if (ainfo.oformats & AFMT_S16_LE)
+        info.m_dataFormats.push_back(AE_FMT_S16LE);
+#endif
+      for (int j = 0;
+        j < ainfo.max_channels && AE_CH_NULL != OSSChannelMap[j];
+        ++j)
+          info.m_channels += OSSChannelMap[j];
+
+      for (int *rate = OSSSampleRateList; *rate != 0; ++rate)
+        if (*rate >= ainfo.min_rate && *rate <= ainfo.max_rate)
+          info.m_sampleRates.push_back(*rate);
+    }
+    list.push_back(info);
+
+    close(audioctlfd);
+  }
+#else
   int mixerfd;
   const char * mixerdev = "/dev/mixer";
 
@@ -505,5 +570,6 @@ void CAESinkOSS::EnumerateDevicesEx(AEDe
   }
 #endif
   close(mixerfd);
+#endif
 }
 
