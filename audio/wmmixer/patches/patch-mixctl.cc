$NetBSD: patch-mixctl.cc,v 1.1 2021/08/13 13:01:51 nia Exp $

Workaround:
modify_counter is not incremented by NetBSD's libossaudio.

--- mixctl.cc.orig	2017-08-27 20:35:35.000000000 +0000
+++ mixctl.cc
@@ -243,16 +243,11 @@ char* MixCtl::getLabel(int dev)
 //----------------------------------------------------------------------
 bool MixCtl::hasChanged()
 {
-  struct mixer_info mixer_info1;
-  ioctl(mixfd, SOUND_MIXER_INFO, &mixer_info1);
-
-  if (mixer_info1.modify_counter == modify_counter)
+  for(int i=0;i<SOUND_MIXER_NRDEVICES;i++)
     {
-      return false;
-    }
-  else
-    {
-      modify_counter = mixer_info1.modify_counter;
-      return true;
+      int val = mixer_devices_[i].value;
+      if(val!=readVol(i, true))
+        return true;
     }
+  return false;
 }
