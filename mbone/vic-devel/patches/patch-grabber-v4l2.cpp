$NetBSD: patch-grabber-v4l2.cpp,v 1.3 2025/01/27 16:35:10 wiz Exp $

--- video/grabber-v4l2.cpp.orig	2008-12-10 19:23:08.000000000 +0000
+++ video/grabber-v4l2.cpp
@@ -34,7 +34,9 @@
 #include <string.h>
 #include <signal.h>
 #include <errno.h>
+#ifdef __Linux__
 #include <endian.h>
+#endif
 
 #include <sys/types.h>
 #include <sys/fcntl.h>
@@ -48,8 +50,12 @@
 
 extern "C"
 {
+#ifdef __NetBSD__
+#include <sys/videoio.h>
+#else
 #include <asm/types.h>
 #include <linux/videodev2.h>
+#endif
 }
 
 #ifdef HAVE_LIBV4L
@@ -108,6 +114,9 @@ static const char *devlist[] = {
 #define V4L2_CID_FOCUS_RELATIVE       (V4L2_CID_PRIVATE_BASE + 6)
 #endif
 
+#undef __u32
+#define __u32 uint32_t
+
 typedef struct tag_vimage
 {
         struct v4l2_buffer      vidbuf;
