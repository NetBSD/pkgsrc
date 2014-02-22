$NetBSD: patch-src_IceCast.cpp,v 1.1 2014/02/22 14:51:03 wiedi Exp $

Fix "log10(int) is ambigous" on SunOS
--- src/IceCast.cpp.orig	2013-07-15 05:50:42.000000000 +0000
+++ src/IceCast.cpp
@@ -145,7 +145,7 @@ IceCast :: sendLogin ( void )
     /* send the x-audiocast headers */
     str = "\nx-audiocast-bitrate: ";
     sink->write( str, strlen( str));
-    if ( log10(getBitRate()) >= (STRBUF_SIZE-2) ) {
+    if ( log10((double)getBitRate()) >= (STRBUF_SIZE-2) ) {
         throw Exception( __FILE__, __LINE__,
                          "bitrate does not fit string buffer", getBitRate());
     }
