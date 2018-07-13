$NetBSD: patch-src_zmu.cpp,v 1.1 2018/07/13 02:05:11 gdt Exp $

--- src/zmu.cpp.orig	2015-02-05 02:52:37.000000000 +0000
+++ src/zmu.cpp
@@ -457,7 +457,7 @@ int main( int argc, char *argv[] )
 				else
 				{
 					if ( have_output ) printf( "%c", separator );
-					printf( "%ld.%02ld", timestamp.tv_sec, timestamp.tv_usec/10000 );
+					printf( "%ld.%02ld", (long) timestamp.tv_sec, timestamp.tv_usec/10000 );
 					have_output = true;
 				}
 			}
@@ -729,7 +729,7 @@ int main( int argc, char *argv[] )
 								function,
 								monitor->GetState(),
 								monitor->GetTriggerState(),
-								tv.tv_sec, tv.tv_usec/10000,
+								(long) tv.tv_sec, tv.tv_usec/10000,
 								monitor->GetLastReadIndex(),
 								monitor->GetLastWriteIndex(),
 								monitor->GetLastEvent(),
@@ -746,7 +746,7 @@ int main( int argc, char *argv[] )
 							function,
 							0,
 							0,
-							tv.tv_sec, tv.tv_usec/10000,
+							(long) tv.tv_sec, tv.tv_usec/10000,
 							0,
 							0,
 							0,
