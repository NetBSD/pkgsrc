--- video/grabber-v4l2.cpp.orig	2008-12-13 22:12:50.000000000 +0000
+++ video/grabber-v4l2.cpp	2008-12-13 22:14:26.000000000 +0000
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
