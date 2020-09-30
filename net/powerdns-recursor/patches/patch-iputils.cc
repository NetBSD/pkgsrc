$NetBSD: patch-iputils.cc,v 1.3 2020/09/30 11:53:07 otis Exp $

Silence the warning about defined but not used variable on
apropriate platforms.

--- iputils.cc.orig	2020-09-04 17:20:52.000000000 +0000
+++ iputils.cc
@@ -322,7 +322,9 @@ size_t sendMsgWithOptions(int fd, const
   msgh.msg_flags = 0;
 
   size_t sent = 0;
+#ifdef MSG_FASTOPEN
   bool firstTry = true;
+#endif
 
   do {
 
@@ -342,8 +344,10 @@ size_t sendMsgWithOptions(int fd, const
         return sent;
       }
 
+#ifdef MSG_FASTOPEN
       /* partial write */
       firstTry = false;
+#endif
       iov.iov_len -= written;
       iov.iov_base = reinterpret_cast<void*>(reinterpret_cast<char*>(iov.iov_base) + written);
       written = 0;
