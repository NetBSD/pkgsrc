$NetBSD: patch-src_backends_alc__backend__darwin.c,v 1.1 2014/01/10 08:58:01 pho Exp $

Convert C++ style comments to C style ones to fix build on Darwin.

--- src/backends/alc_backend_darwin.c.orig	2014-01-10 08:52:31.000000000 +0000
+++ src/backends/alc_backend_darwin.c
@@ -112,19 +112,19 @@ OSStatus GetAudioDevices (void **devices
 
     DebugPrintf("OpenAL MOSX Backend : Build %d\n",buildID);
 
-    // find out how many audio devices there are, if any
+    /* find out how many audio devices there are, if any */
     err = AudioHardwareGetPropertyInfo(kAudioHardwarePropertyDevices, &outSize, &outWritable);
     if (err != NULL) return (err);
 
-    // calculate the number of device available
+    /* calculate the number of device available */
     *devicesAvailable = outSize / sizeof(AudioDeviceID);
-    // Bail if there aren't any devices
+    /* Bail if there aren't any devices */
     if (*devicesAvailable < 1) return (-1);
 
-    // make space for the devices we are about to get
+    /* make space for the devices we are about to get */
     if (*devices != NULL) free(*devices);
     *devices = malloc(outSize);
-    // get an array of AudioDeviceIDs
+    /* get an array of AudioDeviceIDs */
     err = AudioHardwareGetProperty(kAudioHardwarePropertyDevices, &outSize, (void *) *devices);
     if (err != NULL) free(*devices);
 #ifdef DEBUG_MAXIMUS
@@ -259,8 +259,8 @@ static ALboolean set_write_native(UNUSED
 
     DebugPrintf("Init Speed : %d\n",*speed);
 
-    //*fmt = AL_FORMAT_STEREO16;
-    //*speed = (unsigned int)libGlobals.deviceFormat.mSampleRate;
+    /* *fmt = AL_FORMAT_STEREO16; */
+    /* *speed = (unsigned int)libGlobals.deviceFormat.mSampleRate; */
 
     alWriteFormat = *fmt;
 
@@ -324,7 +324,7 @@ void  native_blitbuffer(void *handle, vo
         return;
     }
 
-    // Gyom FIXME: Is this useful?
+    /* Gyom FIXME: Is this useful? */
     assert(nativePreferedBuffSize <= bytes);
 
     playABuffer(data);
