$NetBSD: patch-include_sound_uapi_asound.h,v 1.1 2021/05/12 14:12:13 ryoon Exp $

--- include/sound/uapi/asound.h.orig	2020-06-29 10:51:08.000000000 +0000
+++ include/sound/uapi/asound.h
@@ -545,12 +545,12 @@ struct __snd_pcm_sync_ptr {
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
