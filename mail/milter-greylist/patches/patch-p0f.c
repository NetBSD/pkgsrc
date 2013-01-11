$NetBSD: patch-p0f.c,v 1.4 2013/01/11 13:23:17 tron Exp $

Build fix for Solaris 11.

--- p0f.c.orig	2013-01-08 14:30:01.000000000 +0000
+++ p0f.c
@@ -116,25 +116,25 @@ strcasestr ( haystack, needle )
 #define RESP_NOMATCH		2
 
 struct p0f_query {
-	u_int32_t	magic;
-	u_int8_t	type;
-	u_int32_t	id;
-	u_int32_t	src_ad,dst_ad;
-	u_int16_t	src_port,dst_port;
+	uint32_t	magic;
+	uint8_t	type;
+	uint32_t	id;
+	uint32_t	src_ad,dst_ad;
+	uint16_t	src_port,dst_port;
 };
 struct p0f_response {
-	u_int32_t	magic;
-	u_int32_t	id;
-	u_int8_t 	type;
-	u_int8_t	genre[20];
-	u_int8_t	detail[40];
+	uint32_t	magic;
+	uint32_t	id;
+	uint8_t 	type;
+	uint8_t	genre[20];
+	uint8_t	detail[40];
 	int8_t		dist;
-	u_int8_t	link[30];
-	u_int8_t	tos[30];
-	u_int8_t	fw,nat;
-	u_int8_t	real;
+	uint8_t	link[30];
+	uint8_t	tos[30];
+	uint8_t	fw,nat;
+	uint8_t	real;
 	int16_t		score;
-	u_int16_t	mflags;
+	uint16_t	mflags;
 	int32_t		uptime;
 };
 /* End of stuff borrowed from p0f/p0f-query.h */
