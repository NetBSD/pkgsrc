$NetBSD: patch-src_zmu.cpp,v 1.3 2020/08/25 16:42:21 gdt Exp $

time types

--- src/zmu.cpp.orig	2016-02-03 18:40:30.000000000 +0000
+++ src/zmu.cpp
@@ -519,14 +519,14 @@ int main( int argc, char *argv[] )
 					if ( timestamp.tv_sec )
 						strftime( timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", localtime( &timestamp.tv_sec ) );
 					if ( image_idx == -1 )
-						printf( "Time of last image capture: %s.%02ld\n", timestamp_str, timestamp.tv_usec/10000 );
+						printf( "Time of last image capture: %s.%02ld\n", timestamp_str, (long) timestamp.tv_usec/10000 );
 					else
-						printf( "Time of image %d capture: %s.%02ld\n", image_idx, timestamp_str, timestamp.tv_usec/10000 );
+						printf( "Time of image %d capture: %s.%02ld\n", image_idx, timestamp_str, (long) timestamp.tv_usec/10000 );
 				}
 				else
 				{
 					if ( have_output ) printf( "%c", separator );
-					printf( "%ld.%02ld", timestamp.tv_sec, timestamp.tv_usec/10000 );
+					printf( "%jd.%02ld", (intmax_t) timestamp.tv_sec, (long) timestamp.tv_usec/10000 );
 					have_output = true;
 				}
 			}
@@ -793,12 +793,12 @@ int main( int argc, char *argv[] )
 						if ( monitor && monitor->connect() )
 						{
 							struct timeval tv = monitor->GetTimestamp();
-							printf( "%4d%5d%6d%9d%11ld.%02ld%6d%6d%8d%8.2f\n",
+							printf( "%4d%5d%6d%9d%11jd.%02ld%6d%6d%8d%8.2f\n",
 								monitor->Id(),
 								function,
 								monitor->GetState(),
 								monitor->GetTriggerState(),
-								tv.tv_sec, tv.tv_usec/10000,
+								(intmax_t) tv.tv_sec, (long) tv.tv_usec/10000,
 								monitor->GetLastReadIndex(),
 								monitor->GetLastWriteIndex(),
 								monitor->GetLastEvent(),
@@ -810,12 +810,12 @@ int main( int argc, char *argv[] )
 					else
 					{
 						struct timeval tv = { 0, 0 };
-						printf( "%4d%5d%6d%9d%11ld.%02ld%6d%6d%8d%8.2f\n",
+						printf( "%4d%5d%6d%9d%11jd.%02ld%6d%6d%8d%8.2f\n",
 							mon_id,
 							function,
 							0,
 							0,
-							tv.tv_sec, tv.tv_usec/10000,
+							(intmax_t) tv.tv_sec, (long) tv.tv_usec/10000,
 							0,
 							0,
 							0,
