$NetBSD: patch-rec__channel.cc,v 1.3 2015/06/10 14:22:29 fhajny Exp $

We need to include cstring

--- rec_channel.cc.orig	2015-04-21 13:02:57.000000000 +0000
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
   if(makeUNsockaddr(fname, &d_local))
     throw PDNSException("Unable to bind to controlsocket, path '"+fname+"' is not a valid UNIX socket path.");
     
-  if(bind(d_fd, (sockaddr*)&d_local,sizeof(d_local))<0) 
+  if(::bind(d_fd, (sockaddr*)&d_local,sizeof(d_local))<0) 
     throw PDNSException("Unable to bind to controlsocket '"+fname+"': "+stringerror());
 
   return d_fd;
@@ -79,7 +80,7 @@ void RecursorControlChannel::connect(con
     if(err < 0 && errno!=ENOENT)
       throw PDNSException("Unable to remove local controlsocket: "+stringerror());
 
-    if(bind(d_fd, (sockaddr*)&d_local,sizeof(d_local))<0)
+    if(::bind(d_fd, (sockaddr*)&d_local,sizeof(d_local))<0)
       throw PDNSException("Unable to bind to local temporary file: "+stringerror());
 
     if(chmod(d_local.sun_path,0666)<0) // make sure that pdns can reply!
