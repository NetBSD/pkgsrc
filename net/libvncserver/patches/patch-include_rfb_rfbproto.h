$NetBSD: patch-include_rfb_rfbproto.h,v 1.1 2025/05/04 09:47:18 nia Exp $

Fix endianess detection on NetBSD

--- include/rfb/rfbproto.h.orig	2025-05-04 07:48:23.564794224 +0000
+++ include/rfb/rfbproto.h
@@ -78,8 +78,9 @@ typedef int8_t rfbBool;
 #endif
 
 #if LIBVNCSERVER_HAVE_ENDIAN_H
+# define _XOPEN_SOURCE
 # include <endian.h>
-# if __BYTE_ORDER == __BIG_ENDIAN
+# if BYTE_ORDER == BIG_ENDIAN
 #  define LIBVNCSERVER_WORDS_BIGENDIAN 1
 # endif
 #endif
