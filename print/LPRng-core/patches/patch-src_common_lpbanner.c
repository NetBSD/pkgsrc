$NetBSD: patch-src_common_lpbanner.c,v 1.1 2011/11/25 22:15:18 joerg Exp $

--- src/common/lpbanner.c.orig	2011-11-25 13:32:31.000000000 +0000
+++ src/common/lpbanner.c
@@ -1540,7 +1540,7 @@ void banner(void)
 		strncpy( jobnumber, controlfile+3, 3 );
 		jobnumber[3] = 0;
 	}
-	if(jobnumber && *jobnumber ) seebig( &len, Font9x8.height, &bigjobnumber );
+	if( *jobnumber ) seebig( &len, Font9x8.height, &bigjobnumber );
 	if(bnrname && *bnrname) seebig( &len, Font9x8.height, &biglogname );
 	if(host && *host ) seebig( &len, Font9x8.height, &bigfromhost );
 	if(job && *job) seebig( &len, Font9x8.height, &bigjobname );
