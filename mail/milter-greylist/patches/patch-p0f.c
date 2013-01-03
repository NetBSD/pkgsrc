$NetBSD: patch-p0f.c,v 1.2 2013/01/03 09:50:44 tron Exp $

. More portable int types.
. Use strstr(3) in place of strcasestr(3) under SunOS.
. Rename 'sun' to 's_un' to avoid a conflict on SunOS.

--- p0f.c.orig	2012-02-21 05:53:44.000000000 +0000
+++ p0f.c	2012-12-30 13:40:25.000000000 +0000
@@ -75,25 +75,25 @@
 #define RESP_NOMATCH		2
 
 struct p0f_query {
-	u_int32_t	magic;
-	u_int8_t	type;
-	u_int32_t	id;
-	u_int32_t	src_ad,dst_ad;
-	u_int16_t	src_port,dst_port;
+	uint32_t	magic;
+	uint8_t		type;
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
+	uint8_t		genre[20];
+	uint8_t		detail[40];
 	int8_t		dist;
-	u_int8_t	link[30];
-	u_int8_t	tos[30];
-	u_int8_t	fw,nat;
-	u_int8_t	real;
+	uint8_t		link[30];
+	uint8_t		tos[30];
+	uint8_t		fw,nat;
+	uint8_t		real;
 	int16_t		score;
-	u_int16_t	mflags;
+	uint16_t	mflags;
 	int32_t		uptime;
 };
 /* End of stuff borrowed from p0f/p0f-query.h */
@@ -159,7 +159,11 @@
                return 0;
 
 	data = (char *)ad->string;
+#ifdef __sun__
+	if (strstr(priv->priv_p0f, data) != NULL)
+#else
 	if (strcasestr(priv->priv_p0f, data) != NULL)
+#endif
 		return 1;
 	return 0;
 }
@@ -404,7 +408,7 @@
 static int
 p0f_connect(void)
 {
-	struct sockaddr_un sun;
+	struct sockaddr_un s_un;
 	int p0fsock = -1;
 
 	if (!conf.c_p0fsock[0])
@@ -424,11 +428,11 @@
 
 	if (conf.c_debug)
 		mg_log(LOG_DEBUG, "using p0f socket \"%s\"", conf.c_p0fsock);		
-	(void)memset(&sun, 0, sizeof(sun));
-	sun.sun_family = AF_UNIX;
-	strncpy(sun.sun_path, conf.c_p0fsock, sizeof(sun.sun_path));
+	(void)memset(&s_un, 0, sizeof(s_un));
+	s_un.sun_family = AF_UNIX;
+	strncpy(s_un.sun_path, conf.c_p0fsock, sizeof(s_un.sun_path));
 
-	if (connect(p0fsock, (struct sockaddr *)&sun, sizeof(sun)) != 0) {
+	if (connect(p0fsock, (struct sockaddr *)&s_un, sizeof(s_un)) != 0) {
 		mg_log(LOG_ERR, "Cannot connect to p0f socket \"%s\"",
 		      conf.c_p0fsock);	
 		close(p0fsock);
