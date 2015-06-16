$NetBSD: patch-libgrive_src_util_OS.cc,v 1.1.1.1 2015/06/16 16:15:37 abs Exp $

Add __NetBSD__ to the 64bit Apple ctimespec stat case

--- libgrive/src/util/OS.cc.orig	2015-05-31 19:35:15.000000000 +0000
+++ libgrive/src/util/OS.cc
@@ -57,7 +57,7 @@ DateTime FileCTime( const std::string& f
 		) ;
 	}
 	
-#if defined __APPLE__ && defined __DARWIN_64_BIT_INO_T
+#if defined __NetBSD__ || ( defined __APPLE__ && defined __DARWIN_64_BIT_INO_T )
 	return DateTime( s.st_ctimespec.tv_sec, s.st_ctimespec.tv_nsec ) ;
 #else
 	return DateTime( s.st_ctim.tv_sec, s.st_ctim.tv_nsec);
