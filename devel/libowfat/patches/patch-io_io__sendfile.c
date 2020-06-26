$NetBSD: patch-io_io__sendfile.c,v 1.1 2020/06/26 19:21:52 schmonz Exp $

Fix Illumos build.

--- io/io_sendfile.c.orig	2014-06-05 19:17:24.000000000 +0000
+++ io/io_sendfile.c
@@ -49,7 +49,9 @@ int64 io_sendfile(int64 out,int64 in,uin
 
 #elif defined (__sun__) && defined(__svr4__)
 
+#ifndef _LARGEFILE64_SOURCE
 #define _LARGEFILE64_SOURCE
+#endif
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/sendfile.h>
@@ -59,7 +61,7 @@ int64 io_sendfile(int64 out,int64 in,uin
   long long r=sendfile64(out,in,&o,bytes);
   if (r==-1 && errno!=EAGAIN) r=-3;
   if (r!=bytes) {
-    io_entry* e=iarray_get(&io_fds,s);
+    io_entry* e=iarray_get(&io_fds,out);
     if (e) {
       e->canwrite=0;
       e->next_write=-1;
