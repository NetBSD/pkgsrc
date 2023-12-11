$NetBSD: patch-include_sound_uapi_asound.h,v 1.2 2023/12/11 15:41:35 jperkin Exp $

SunOS needs sys/byteorder.h

--- include/sound/uapi/asound.h.orig	2023-09-01 15:35:48.000000000 +0000
+++ include/sound/uapi/asound.h
@@ -28,7 +28,11 @@
 #include <linux/types.h>
 #include <asm/byteorder.h>
 #else
+#ifdef __sun
+#include <sys/byteorder.h>
+#else
 #include <sys/endian.h>
+#endif
 #include <sys/ioctl.h>
 #endif
 
@@ -549,12 +553,12 @@ struct __snd_pcm_sync_ptr {
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
