$NetBSD: patch-include_sound_uapi_asound.h,v 1.3 2025/01/07 12:49:52 wiz Exp $

SunOS needs sys/byteorder.h

--- include/sound/uapi/asound.h.orig	2024-11-12 09:36:52.000000000 +0000
+++ include/sound/uapi/asound.h
@@ -12,7 +12,11 @@
 #include <linux/types.h>
 #include <asm/byteorder.h>
 #else
+#ifdef __sun
+#include <sys/byteorder.h>
+#else
 #include <endian.h>
+#endif
 #include <sys/ioctl.h>
 #endif
 
@@ -550,12 +554,12 @@ struct __snd_pcm_sync_ptr {
 	} c;
 };
 
-#if defined(__BYTE_ORDER) ? __BYTE_ORDER == __BIG_ENDIAN : defined(__BIG_ENDIAN)
+#if (defined(__BYTE_ORDER) ? __BYTE_ORDER == __BIG_ENDIAN : defined(__BIG_ENDIAN)) || (defined(BYTE_ORDER) ? BYTE_ORDER == BIG_ENDIAN : defined(BIG_ENDIAN))
 typedef char __pad_before_uframe[sizeof(__u64) - sizeof(snd_pcm_uframes_t)];
 typedef char __pad_after_uframe[0];
 #endif
 
-#if defined(__BYTE_ORDER) ? __BYTE_ORDER == __LITTLE_ENDIAN : defined(__LITTLE_ENDIAN)
+#if defined(__BYTE_ORDER) ? __BYTE_ORDER == __LITTLE_ENDIAN : defined(__LITTLE_ENDIAN) || defined(BYTE_ORDER) ? BYTE_ORDER == LITTLE_ENDIAN : defined(LITTLE_ENDIAN)
 typedef char __pad_before_uframe[0];
 typedef char __pad_after_uframe[sizeof(__u64) - sizeof(snd_pcm_uframes_t)];
 #endif
