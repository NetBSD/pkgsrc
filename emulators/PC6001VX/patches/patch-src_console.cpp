$NetBSD: patch-src_console.cpp,v 1.1 2026/04/08 13:39:14 tsutsui Exp $

- Appease "type(3) isprint: invalid input: -106" assertion during startup
  by strict NetBSD 11 ctype(3).

--- src/console.cpp.orig	2026-04-08 10:55:26.368043367 +0000
+++ src/console.cpp
@@ -288,7 +288,7 @@ void ZCons::sprintc( const std::string& 
 			break;
 			
 		default:	// 普通の文字
-			if( std::isprint( str[i] ) ){
+			if( std::isprint( (int)(BYTE)str[i] ) ){
 				PutCharH( str[i] );
 			}else{
 				PutCharZ( ((BYTE)str[i] << 8) | (BYTE)str[i+1] );
@@ -324,7 +324,7 @@ void ZCons::sprintr( const std::string& 
 	Locate( x - num + 1, y );
 	
 	for( size_t i = max( str.length() - num, 0 ); i < str.length(); i++ ){
-		if( std::isprint( str[i] ) ){
+		if( std::isprint( (int)(BYTE)str[i] ) ){
 			PutCharH( str[i] );
 		}else{
 			PutCharZ( ((BYTE)str[i] << 8) | (BYTE)str[i+1] );
