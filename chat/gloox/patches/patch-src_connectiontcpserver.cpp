$NetBSD: patch-src_connectiontcpserver.cpp,v 1.3 2016/08/30 15:20:47 schnoebe Exp $

Make sure string.h is included for memset and friends.
Assume it's needed for all non-_WIN32_CE operating systems.
(hmm, this should probably be determined by configure, and handled in config.h)

--- src/connectiontcpserver.cpp.orig	2016-08-23 13:55:51.000000000 +0000
+++ src/connectiontcpserver.cpp
@@ -55,6 +55,7 @@
 
 #ifndef _WIN32_WCE
 # include <sys/types.h>
+# include <string.h>
 #endif
 
 // remove for 1.1
