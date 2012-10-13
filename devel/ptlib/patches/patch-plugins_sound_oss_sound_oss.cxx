$NetBSD: patch-plugins_sound_oss_sound_oss.cxx,v 1.2 2012/10/13 00:49:38 darcy Exp $

- Add DragonFly support

--- plugins/sound_oss/sound_oss.cxx.orig	2012-08-23 02:12:47.000000000 +0000
+++ plugins/sound_oss/sound_oss.cxx
@@ -183,6 +183,12 @@ static void CollectSoundDevices(PDirecto
               devname = devdir + "dsp" + numbers;
               PTRACE(1, "OSS\tCollectSoundDevices FreeBSD devname set to devfs(5) name:" << devname );
 #endif /* defined (P_FREEBSD) */
+#if defined (P_DRAGONFLY)
+              // Same as FreeBSD
+              devname = devdir + "dsp0";
+              PTRACE(1, "OSS\tCollectSoundDevices DragonFly devname set to devfs(5) name:" << devname );
+#endif /* defined (P_DRAGONFLY) */
+
               dsp.SetAt(cardnum+1, devname);
             }
           }
