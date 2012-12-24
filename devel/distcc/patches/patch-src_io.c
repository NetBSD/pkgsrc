$NetBSD: patch-src_io.c,v 1.1 2012/12/24 13:45:02 ryoon Exp $

--- src/io.c.orig	2008-12-02 21:50:25.000000000 +0000
+++ src/io.c
@@ -242,7 +242,7 @@ int dcc_writex(int fd, const void *buf, 
  **/
 int tcp_cork_sock(int POSSIBLY_UNUSED(fd), int POSSIBLY_UNUSED(corked))
 {
-#ifdef TCP_CORK
+#if defined(TCP_CORK) && defined(SOL_TCP)
     if (!dcc_getenv_bool("DISTCC_TCP_CORK", 1))
         return 0;
 
