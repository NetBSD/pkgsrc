$NetBSD: patch-rfb_rfbproto.h,v 1.1 2018/07/18 17:55:54 bouyer Exp $
Fix endianess detection on NetBSD

--- rfb/rfbproto.h.orig	2018-07-18 19:35:56.445752955 +0200
+++ rfb/rfbproto.h	2018-07-18 19:36:17.076925368 +0200
@@ -82,8 +82,11 @@
 #endif
 
 #if LIBVNCSERVER_HAVE_ENDIAN_H
+#define _XOPEN_SOURCE
 # include <endian.h>
-# if __BYTE_ORDER == __BIG_ENDIAN
+# if defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN
+#  define LIBVNCSERVER_WORDS_BIGENDIAN 1
+# elsif defined(_BYTE_ORDER) && BYTE_ORDER == BIG_ENDIAN
 #  define LIBVNCSERVER_WORDS_BIGENDIAN 1
 # endif
 #endif
