$NetBSD: patch-src_zmf.cpp,v 1.2 2019/12/19 22:23:19 joerg Exp $

bind can be found in namespace std too.
Fix error handling.

--- src/zmf.cpp.orig	2015-02-05 02:52:37.000000000 +0000
+++ src/zmf.cpp
@@ -59,7 +59,7 @@ int OpenSocket( int monitor_id )
 	strncpy( addr.sun_path, sock_path, sizeof(addr.sun_path) );
 	addr.sun_family = AF_UNIX;
 
-	if ( bind( sd, (struct sockaddr *)&addr, strlen(addr.sun_path)+sizeof(addr.sun_family)) < 0 )
+	if ( ::bind( sd, (struct sockaddr *)&addr, strlen(addr.sun_path)+sizeof(addr.sun_family)) < 0 )
 	{
 		Error( "Can't bind: %s", strerror(errno) );
 		exit( -1 );
@@ -293,7 +293,7 @@ int main( int argc, char *argv[] )
 		Debug( 1, "Got image, writing to %s", path );
 
 		FILE *fd = 0;
-		if ( (fd = fopen( path, "w" )) < 0 )
+		if ( (fd = fopen( path, "w" )) == 0 )
 		{
 			Error( "Can't fopen '%s': %s", path, strerror(errno) );
 			exit( -1 );
