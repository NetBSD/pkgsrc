$NetBSD: patch-senario.cc,v 1.1 2020/01/02 09:56:49 tsutsui Exp $

Appease LP64 warnings.

--- senario.cc.orig	2008-01-06 06:20:00.000000000 +0000
+++ senario.cc
@@ -1241,7 +1241,7 @@ int SENARIO_DECODE::Decode(void)
 #endif
 				break;
 #else			/* 終端をきちんと検知する */
-				printf("Error: cmd 0x00, seen %d, point %d: invalid data len?\n",seen_no,data-basedata);
+				printf("Error: cmd 0x00, seen %d, point %d: invalid data len?\n",seen_no,(int)(data-basedata));
 #endif
 				goto error;
 			}
@@ -3100,7 +3100,7 @@ void SENARIO_DECODE::DumpData(void) {
 	unsigned char* d = data; d -= 0x50;
 	if (d < basedata) d = basedata;
 	int i; for (i=0; i<20; i++) {
-		printf("%6x: ",d-basedata);
+		printf("%6x: ",(int)(d-basedata));
 		int j; for (j=0; j<16; j++) {
 			printf("%02x ",int(*d++)&0xff);
 		}
