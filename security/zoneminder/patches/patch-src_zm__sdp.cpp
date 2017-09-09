$NetBSD: patch-src_zm__sdp.cpp,v 1.1 2017/09/09 07:55:31 alnsn Exp $

Commit f5ef721: Add IP6 address type to valid types for ConnInfo.

--- src/zm_sdp.cpp.orig	2015-02-05 02:52:37.000000000 +0000
+++ src/zm_sdp.cpp
@@ -112,7 +112,7 @@ SessionDescriptor::ConnInfo::ConnInfo( c
     if ( mNetworkType != "IN" )
         throw Exception( "Invalid SDP network type '"+mNetworkType+"' in connection info '"+connInfo+"'" );
     mAddressType = tokens[1];
-    if ( mAddressType != "IP4" )
+    if ( mAddressType != "IP4" && mAddressType != "IP6" )
         throw Exception( "Invalid SDP address type '"+mAddressType+"' in connection info '"+connInfo+"'" );
     StringVector addressTokens = split( tokens[2], "/" );
     if ( addressTokens.size() < 1 ) 
