$NetBSD: patch-include_sound_asoc.h,v 1.1 2016/02/18 15:15:57 wiz Exp $

--- include/sound/asoc.h.orig	2015-11-09 07:39:18.000000000 +0000
+++ include/sound/asoc.h
@@ -111,6 +111,16 @@
  * Block Header.
  * This header precedes all object and object arrays below.
  */
+#ifndef __le16
+#define __le16 uint16_t
+#endif
+#ifndef __le32
+#define __le32 uint32_t
+#endif
+#ifndef __le64
+#define __le64 uint64_t
+#endif
+
 struct snd_soc_tplg_hdr {
 	__le32 magic;		/* magic number */
 	__le32 abi;		/* ABI version */
