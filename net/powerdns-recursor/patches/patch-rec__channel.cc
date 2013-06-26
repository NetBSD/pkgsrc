$NetBSD: patch-rec__channel.cc,v 1.2 2013/06/26 15:52:22 joerg Exp $

We need to include cstring

--- rec_channel.cc.orig	2010-09-21 16:22:09.000000000 +0000
+++ rec_channel.cc
@@ -4,6 +4,7 @@
 #include "misc.hh"
 #include <string.h>
 #include <cstdlib>
+#include <cstring>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -46,7 +47,7 @@ int RecursorControlChannel::listen(const
   d_local.sun_family=AF_UNIX;
   strcpy(d_local.sun_path, fname.c_str());
     
-  if(bind(d_fd, (sockaddr*)&d_local,sizeof(d_local))<0) 
+  if(::bind(d_fd, (sockaddr*)&d_local,sizeof(d_local))<0) 
     throw AhuException("Unable to bind to controlsocket '"+fname+"': "+string(strerror(errno)));
 
   return d_fd;
@@ -84,7 +85,7 @@ void RecursorControlChannel::connect(con
   if(err < 0 && errno!=ENOENT)
     throw AhuException("Unable to remove local controlsocket: "+string(strerror(errno)));
 
-  if(bind(d_fd, (sockaddr*)&d_local,sizeof(d_local))<0) {
+  if(::bind(d_fd, (sockaddr*)&d_local,sizeof(d_local))<0) {
     unlink(d_local.sun_path);
     close(d_fd);
     d_fd=-1;
