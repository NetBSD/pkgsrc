$NetBSD: patch-src_zmu.cpp,v 1.2 2018/07/14 15:03:57 gdt Exp $

--- src/zmu.cpp.orig	2015-02-05 02:52:37.000000000 +0000
+++ src/zmu.cpp
@@ -457,7 +457,7 @@ int main( int argc, char *argv[] )
 				else
 				{
 					if ( have_output ) printf( "%c", separator );
-					printf( "%ld.%02ld", timestamp.tv_sec, timestamp.tv_usec/10000 );
+					printf( "%jd.%02ld", (intmax_t) timestamp.tv_sec, timestamp.tv_usec/10000 );
 					have_output = true;
 				}
 			}
@@ -724,12 +724,12 @@ int main( int argc, char *argv[] )
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
+								(intmax_t) tv.tv_sec, tv.tv_usec/10000,
 								monitor->GetLastReadIndex(),
 								monitor->GetLastWriteIndex(),
 								monitor->GetLastEvent(),
@@ -741,12 +741,12 @@ int main( int argc, char *argv[] )
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
+							(intmax_t) tv.tv_sec, tv.tv_usec/10000,
 							0,
 							0,
 							0,
