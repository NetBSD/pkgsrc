$NetBSD: patch-sysdep_bsd_krt-sock.c,v 1.1 2017/09/25 22:29:06 joerg Exp $

RTF_LLDATA is used by NetBSD 8+, RTF_LLINFO before.

--- sysdep/bsd/krt-sock.c.orig	2017-09-25 12:08:47.512663756 +0000
+++ sysdep/bsd/krt-sock.c
@@ -349,8 +349,14 @@ krt_read_route(struct ks_msg *msg, struc
   if (!(flags & RTF_DONE) && !scan)
     SKIP("not done in async\n");
 
+#ifdef RTF_LLINFO
   if (flags & RTF_LLINFO)
     SKIP("link-local\n");
+#endif
+#ifdef RTF_LLDATA
+  if (flags & RTF_LLDATA)
+    SKIP("link-local\n");
+#endif
 
 #ifdef KRT_SHARED_SOCKET
   if (!scan)
