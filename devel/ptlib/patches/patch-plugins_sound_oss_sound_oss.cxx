$NetBSD: patch-plugins_sound_oss_sound_oss.cxx,v 1.1 2011/12/04 21:59:37 marino Exp $

--- plugins/sound_oss/sound_oss.cxx.orig	2009-09-21 00:25:31.000000000 +0000
+++ plugins/sound_oss/sound_oss.cxx
@@ -182,6 +182,11 @@ static void CollectSoundDevices(PDirecto
               devname = devdir + "dsp0";
               PTRACE(1, "OSS\tCollectSoundDevices FreeBSD devname set to devfs(5) name:" << devname );
 #endif /* defined (P_FREEBSD) */
+#if defined (P_DRAGONFLY)
+              // Same as FreeBSD
+              devname = devdir + "dsp0";
+              PTRACE(1, "OSS\tCollectSoundDevices DragonFly devname set to devfs(5) name:" << devname );
+#endif /* defined (P_DRAGONFLY) */
               dsp.SetAt(cardnum+1, devname);
             }
           }
