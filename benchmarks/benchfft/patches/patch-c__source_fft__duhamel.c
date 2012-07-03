$NetBSD: patch-c__source_fft__duhamel.c,v 1.1 2012/07/03 18:19:17 joerg Exp $

--- c_source/fft_duhamel.c.orig	2012-07-03 12:48:09.000000000 +0000
+++ c_source/fft_duhamel.c
@@ -44,7 +44,7 @@ int np ;
 			*(py + i) = 0.0; 
 		};
 		printf("\nuse %d point fft",n); 
-		return;
+		return n;
 	}
 
 	n2 = n+n;
