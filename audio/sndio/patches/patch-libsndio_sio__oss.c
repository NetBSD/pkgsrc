$NetBSD: patch-libsndio_sio__oss.c,v 1.1 2025/11/15 21:38:43 vins Exp $

Add missing bits for ossaudio(3) on NetBSD.

--- libsndio/sio_oss.c.orig	2024-08-01 15:36:54.000000000 +0000
+++ libsndio/sio_oss.c
@@ -37,6 +37,22 @@
 	sizeof(DEVPATH_PREFIX) - 1 +	\
 	sizeof(int) * 3)
 
+/*
+ * Additional OSS formats definitions.
+ */
+#ifndef AFMT_U32_LE
+#define AFMT_U32_LE 0x00004000	/* Little endian unsigned 32-bit */
+#endif
+#ifndef AFMT_U32_BE
+#define AFMT_U32_BE 0x00008000	/* Big endian unsigned 32-bit */
+#endif
+#ifndef AFMT_U24_LE
+#define AFMT_U24_LE 0x00040000	/* Little endian unsigned 24-bit */
+#endif
+#ifndef AFMT_U24_BE
+#define AFMT_U24_BE 0x00080000	/* Big endian unsigned 24-bit */
+#endif
+
 struct sio_oss_fmt {
 	int fmt;
 	unsigned int bits;
@@ -288,11 +304,13 @@ sio_oss_getfd(const char *str, unsigned 
 	}
 
 	val = 1;
+#if !defined(__NetBSD__)
 	if (ioctl(fd, SNDCTL_DSP_LOW_WATER, &val) == -1) {
 		DPERROR("sio_oss_start: LOW_WATER");
 		close(fd);
 		return -1;
 	}
+#endif
 	return fd;
 }
 
