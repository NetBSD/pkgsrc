$NetBSD: patch-rfb_rfbproto.h,v 1.2 2022/12/25 18:29:50 wiz Exp $

Fix endianess detection on NetBSD

--- rfb/rfbproto.h.orig	2020-06-13 18:49:53.000000000 +0000
+++ rfb/rfbproto.h
@@ -78,8 +78,13 @@ typedef int8_t rfbBool;
 #endif
 
 #if LIBVNCSERVER_HAVE_ENDIAN_H
+#ifndef _XOPEN_SOURCE
+#define _XOPEN_SOURCE
+#endif
 # include <endian.h>
-# if __BYTE_ORDER == __BIG_ENDIAN
+# if defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN
+#  define LIBVNCSERVER_WORDS_BIGENDIAN 1
+# elsif defined(_BYTE_ORDER) && BYTE_ORDER == BIG_ENDIAN
 #  define LIBVNCSERVER_WORDS_BIGENDIAN 1
 # endif
 #endif
