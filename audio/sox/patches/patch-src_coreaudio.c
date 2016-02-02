$NetBSD: patch-src_coreaudio.c,v 1.1 2016/02/02 06:12:10 dbj Exp $

CoreAudio may return the same device multiple times as separate
input and output devices.  Only try to use the appropriate direction when matching.

--- src/coreaudio.c.orig	2014-10-06 01:59:34.000000000 +0000
+++ src/coreaudio.c
@@ -140,22 +140,33 @@ static int setup(sox_format_t *ft, int i
 
       if (status == noErr)
       {
-          int device_count = property_size/sizeof(AudioDeviceID);
           AudioDeviceID *devices;
 
           devices = malloc(property_size);
-              status = AudioHardwareGetProperty(kAudioHardwarePropertyDevices, &property_size, devices);
+          status = AudioHardwareGetProperty(kAudioHardwarePropertyDevices, &property_size, devices);
 
           if (status == noErr)
           {
               int i;
+              int device_count = property_size/sizeof(AudioDeviceID);
               for (i = 0; i < device_count; i++)
               {
                   char name[256];
-                  status = AudioDeviceGetProperty(devices[i],0,false,kAudioDevicePropertyDeviceName,&property_size,&name);
+                  property_size = sizeof(name);
+                  status = AudioDeviceGetProperty(devices[i], 0, is_input, kAudioDevicePropertyDeviceName, &property_size, &name);
+                  if (status != noErr) {
+                      continue;
+                  }
+                  name[property_size-1] = '\0';
 
                   lsx_report("Found Audio Device \"%s\"\n",name);
 
+                  status = AudioDeviceGetPropertyInfo(devices[i], 0, is_input, kAudioDevicePropertyStreamFormat, NULL, NULL);
+                  if (status != noErr) {
+                      lsx_report("Audio Device \"%s\" at index %d is not an %s device", name, i, is_input ? "input" : "output");
+                      continue;
+                  }
+
                   /* String returned from OS is truncated so only compare
                    * as much as returned.
                    */
