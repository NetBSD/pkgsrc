$NetBSD: patch-libgrive_src_util_OS.cc,v 1.2 2021/04/15 08:42:23 wiz Exp $

Add __NetBSD__ to the 64bit Apple ctimespec stat case

--- libgrive/src/util/OS.cc.orig	2019-11-12 22:05:31.000000000 +0000
+++ libgrive/src/util/OS.cc
@@ -59,7 +59,7 @@ void Stat( const std::string& filename, 
 	
 	if ( t )
 	{
-#if defined __APPLE__ && defined __DARWIN_64_BIT_INO_T
+#if defined __NetBSD__ || ( defined __APPLE__ && defined __DARWIN_64_BIT_INO_T )
 		*t = DateTime( s.st_ctimespec.tv_sec, s.st_ctimespec.tv_nsec ) ;
 #else
 		*t = DateTime( s.st_ctim.tv_sec, s.st_ctim.tv_nsec);
