$NetBSD: patch-src_zm__stream.cpp,v 1.1 2019/12/19 22:23:19 joerg Exp $

bind can be found in namespace std too.

--- src/zm_stream.cpp.orig	2019-12-19 14:24:09.345342211 +0000
+++ src/zm_stream.cpp
@@ -297,7 +297,7 @@ void StreamBase::openComms()
 
         strncpy( loc_addr.sun_path, loc_sock_path, sizeof(loc_addr.sun_path) );
         loc_addr.sun_family = AF_UNIX;
-        if ( bind( sd, (struct sockaddr *)&loc_addr, strlen(loc_addr.sun_path)+sizeof(loc_addr.sun_family)) < 0 )
+        if ( ::bind( sd, (struct sockaddr *)&loc_addr, strlen(loc_addr.sun_path)+sizeof(loc_addr.sun_family)) < 0 )
         {
             Fatal( "Can't bind: %s", strerror(errno) );
         }
