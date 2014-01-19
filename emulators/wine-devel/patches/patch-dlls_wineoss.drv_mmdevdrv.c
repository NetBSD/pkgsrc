$NetBSD: patch-dlls_wineoss.drv_mmdevdrv.c,v 1.1 2014/01/19 10:58:23 adam Exp $

Restore OSSv3 support for NetBSD.

--- dlls/wineoss.drv/mmdevdrv.c.orig	2014-01-03 19:00:47.000000000 +0000
+++ dlls/wineoss.drv/mmdevdrv.c
@@ -55,6 +55,10 @@
 
 WINE_DEFAULT_DEBUG_CHANNEL(oss);
 
+#ifndef HAVE_OSSv4
+#define OSS_DEVNODE_SIZE 255
+#endif
+
 #define NULL_PTR_ERR MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, RPC_X_NULL_REF_POINTER)
 
 static const REFERENCE_TIME DefaultPeriod = 200000;
@@ -112,7 +116,9 @@ struct ACImpl {
     float *vols;
 
     int fd;
+#ifdef HAVE_OSSv4
     oss_audioinfo ai;
+#endif
     char devnode[OSS_DEVNODE_SIZE];
 
     BOOL initted, playing;
@@ -270,7 +276,9 @@ enum DriverPriority {
 int WINAPI AUDDRV_GetPriority(void)
 {
     int mixer_fd;
+#ifdef HAVE_OSSv4
     oss_sysinfo sysinfo;
+#endif
 
     /* Attempt to determine if we are running on OSS or ALSA's OSS
      * compatibility layer. There is no official way to do that, so just check
@@ -283,6 +291,7 @@ int WINAPI AUDDRV_GetPriority(void)
         return Priority_Unavailable;
     }
 
+#ifdef HAVE_OSSv4
     sysinfo.version[0] = 0xFF;
     sysinfo.versionnum = ~0;
     if(ioctl(mixer_fd, SNDCTL_SYSINFO, &sysinfo) < 0){
@@ -290,9 +299,11 @@ int WINAPI AUDDRV_GetPriority(void)
         close(mixer_fd);
         return Priority_Unavailable;
     }
+#endif
 
     close(mixer_fd);
 
+#ifdef HAVE_OSSv4
     if(sysinfo.version[0] < '4' || sysinfo.version[0] > '9'){
         TRACE("Priority_Low: sysinfo.version[0]: %x\n", sysinfo.version[0]);
         return Priority_Low;
@@ -301,6 +312,7 @@ int WINAPI AUDDRV_GetPriority(void)
         TRACE("Priority_Low: sysinfo.versionnum: %x\n", sysinfo.versionnum);
         return Priority_Low;
     }
+#endif
 
     TRACE("Priority_Preferred: Seems like valid OSS!\n");
 
@@ -407,29 +419,34 @@ static UINT get_default_index(EDataFlow 
 {
     int fd = -1, err;
     UINT i;
+#ifdef HAVE_OSSv4
     oss_audioinfo ai;
+#endif
     const char *devnode;
     OSSDevice *dev_item;
 
     if(flow == eRender)
-        fd = open("/dev/dsp", O_WRONLY | O_NONBLOCK);
+        fd = open("/dev/audio", O_WRONLY | O_NONBLOCK);
     else
-        fd = open("/dev/dsp", O_RDONLY | O_NONBLOCK);
+        fd = open("/dev/audio", O_RDONLY | O_NONBLOCK);
 
     if(fd < 0){
         WARN("Couldn't open default device!\n");
         return 0;
     }
 
+#ifdef HAVE_OSSv4
     ai.dev = -1;
     if((err = ioctl(fd, SNDCTL_ENGINEINFO, &ai)) < 0){
         WARN("SNDCTL_ENGINEINFO failed: %d (%s)\n", err, strerror(errno));
         close(fd);
         return 0;
     }
+#endif
 
     close(fd);
 
+#ifdef HAVE_OSSv4
     TRACE("Default devnode: %s\n", ai.devnode);
     devnode = oss_clean_devnode(ai.devnode);
     i = 0;
@@ -440,6 +457,7 @@ static UINT get_default_index(EDataFlow 
             ++i;
         }
     }
+#endif
 
     WARN("Couldn't find default device! Choosing first.\n");
     return 0;
@@ -449,7 +467,9 @@ HRESULT WINAPI AUDDRV_GetEndpointIDs(EDa
         UINT *num, UINT *def_index)
 {
     int i, mixer_fd;
+#ifdef HAVE_OSSv4
     oss_sysinfo sysinfo;
+#endif
     static int print_once = 0;
 
     static const WCHAR outW[] = {'O','u','t',':',' ',0};
@@ -463,6 +483,7 @@ HRESULT WINAPI AUDDRV_GetEndpointIDs(EDa
         return AUDCLNT_E_SERVICE_NOT_RUNNING;
     }
 
+#ifdef HAVE_OSSv4
     if(ioctl(mixer_fd, SNDCTL_SYSINFO, &sysinfo) < 0){
         close(mixer_fd);
 
@@ -575,6 +596,55 @@ HRESULT WINAPI AUDDRV_GetEndpointIDs(EDa
         }
     }
 
+#else
+    *ids = HeapAlloc(GetProcessHeap(), 0, sizeof(WCHAR *));
+    *guids = HeapAlloc(GetProcessHeap(), 0, sizeof(GUID));
+
+    *num = 0;
+    const char *devnode;
+    OSSDevice *dev_item;
+    devnode = oss_clean_devnode("/dev/audio");
+    size_t len, prefix_len;
+    const WCHAR *prefix;
+
+    dev_item = HeapAlloc(GetProcessHeap(), 0, sizeof(*dev_item));
+
+    dev_item->flow = flow;
+    get_device_guid(flow, devnode, &dev_item->guid);
+    strcpy(dev_item->devnode, devnode);
+
+    (*guids)[*num] = dev_item->guid;
+
+    len = MultiByteToWideChar(CP_UNIXCP, 0, "OSS AUDIO", -1, NULL, 0);
+    if(flow == eRender){
+        prefix = outW;
+        prefix_len = (sizeof(outW) / sizeof(*outW)) - 1;
+        len += prefix_len;
+    }else{
+        prefix = inW;
+        prefix_len = (sizeof(inW) / sizeof(*inW)) - 1;
+        len += prefix_len;
+    }
+    (*ids)[*num] = HeapAlloc(GetProcessHeap(), 0,
+            len * sizeof(WCHAR));
+    if(!(*ids)[*num]){
+        for(i = 0; i < *num; ++i)
+            HeapFree(GetProcessHeap(), 0, (*ids)[i]);
+            HeapFree(GetProcessHeap(), 0, *ids);
+            HeapFree(GetProcessHeap(), 0, *guids);
+            HeapFree(GetProcessHeap(), 0, dev_item);
+            close(mixer_fd);
+            return E_OUTOFMEMORY;
+        }
+        memcpy((*ids)[*num], prefix, prefix_len * sizeof(WCHAR));
+        MultiByteToWideChar(CP_UNIXCP, 0, "OSS_AUDIO", -1,
+                (*ids)[*num] + prefix_len, len - prefix_len);
+
+        list_add_tail(&g_devices, &dev_item->entry);
+
+        (*num)++;
+#endif
+
     close(mixer_fd);
 
     *def_index = get_default_index(flow);
@@ -634,6 +704,7 @@ HRESULT WINAPI AUDDRV_GetAudioEndpoint(G
 
     This->dataflow = oss_dev->flow;
 
+#ifdef HAVE_OSSv4
     This->ai.dev = -1;
     if(ioctl(This->fd, SNDCTL_ENGINEINFO, &This->ai) < 0){
         WARN("Unable to get audio info for device %s: %d (%s)\n", oss_dev->devnode,
@@ -642,9 +713,11 @@ HRESULT WINAPI AUDDRV_GetAudioEndpoint(G
         HeapFree(GetProcessHeap(), 0, This);
         return E_FAIL;
     }
+#endif
 
     strcpy(This->devnode, oss_dev->devnode);
 
+#ifdef HAVE_OSSv4
     TRACE("OSS audioinfo:\n");
     TRACE("devnode: %s\n", This->ai.devnode);
     TRACE("name: %s\n", This->ai.name);
@@ -657,6 +730,7 @@ HRESULT WINAPI AUDDRV_GetAudioEndpoint(G
     TRACE("max_rate: %d\n", This->ai.max_rate);
     TRACE("min_channels: %d\n", This->ai.min_channels);
     TRACE("max_channels: %d\n", This->ai.max_channels);
+#endif
 
     This->IAudioClient_iface.lpVtbl = &AudioClient_Vtbl;
     This->IAudioRenderClient_iface.lpVtbl = &AudioRenderClient_Vtbl;
@@ -807,10 +881,12 @@ static int get_oss_format(const WAVEFORM
             return AFMT_U8;
         case 16:
             return AFMT_S16_LE;
+#ifdef HAVE_OSSv4
         case 24:
             return AFMT_S24_LE;
         case 32:
             return AFMT_S32_LE;
+#endif
         }
         return -1;
     }
@@ -1254,10 +1330,14 @@ static HRESULT WINAPI AudioClient_IsForm
             outpwfx = NULL;
     }
 
+#ifndef __NetBSD__
     if(This->dataflow == eRender)
         fd = open(This->devnode, O_WRONLY | O_NONBLOCK, 0);
     else if(This->dataflow == eCapture)
         fd = open(This->devnode, O_RDONLY | O_NONBLOCK, 0);
+#else
+    fd = This->fd;
+#endif
 
     if(fd < 0){
         WARN("Unable to open device %s: %d (%s)\n", This->devnode, errno,
@@ -1267,7 +1347,9 @@ static HRESULT WINAPI AudioClient_IsForm
 
     ret = setup_oss_device(mode, fd, pwfx, outpwfx);
 
+#ifndef __NetBSD__
     close(fd);
+#endif
 
     return ret;
 }
@@ -1285,11 +1367,19 @@ static HRESULT WINAPI AudioClient_GetMix
         return E_POINTER;
     *pwfx = NULL;
 
-    if(This->dataflow == eRender)
+    if(This->dataflow == eRender) {
+#if HAVE_OSSv4
         formats = This->ai.oformats;
-    else if(This->dataflow == eCapture)
+#else
+	formats = AFMT_S16_LE;
+#endif
+    } else if(This->dataflow == eCapture) {
+#if HAVE_OSSv4
         formats = This->ai.iformats;
-    else
+#else
+	formats = AFMT_S16_LE;
+#endif
+    } else
         return E_UNEXPECTED;
 
     fmt = CoTaskMemAlloc(sizeof(WAVEFORMATEXTENSIBLE));
@@ -1308,12 +1398,14 @@ static HRESULT WINAPI AudioClient_GetMix
     }else if(formats & AFMT_U8){
         fmt->Format.wBitsPerSample = 8;
         fmt->SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
+#ifdef HAVE_OSSv4
     }else if(formats & AFMT_S32_LE){
         fmt->Format.wBitsPerSample = 32;
         fmt->SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
     }else if(formats & AFMT_S24_LE){
         fmt->Format.wBitsPerSample = 24;
         fmt->SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
+#endif
     }else{
         WARN("Didn't recognize any available OSS formats: %x\n", formats);
         CoTaskMemFree(fmt);
@@ -1322,16 +1414,22 @@ static HRESULT WINAPI AudioClient_GetMix
 
     /* some OSS drivers are buggy, so set reasonable defaults if
      * the reported values seem wacky */
+#ifdef HAVE_OSSv4
     fmt->Format.nChannels = max(This->ai.max_channels, This->ai.min_channels);
     if(fmt->Format.nChannels == 0 || fmt->Format.nChannels > 8)
+#endif
         fmt->Format.nChannels = 2;
 
+#ifdef HAVE_OSSv4
     if(This->ai.max_rate == 0)
+#endif
         fmt->Format.nSamplesPerSec = 44100;
+#ifdef HAVE_OSSv4
     else
         fmt->Format.nSamplesPerSec = min(This->ai.max_rate, 44100);
     if(fmt->Format.nSamplesPerSec < This->ai.min_rate)
         fmt->Format.nSamplesPerSec = This->ai.min_rate;
+#endif
 
     fmt->dwChannelMask = get_channel_mask(fmt->Format.nChannels);
 
