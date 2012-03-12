$NetBSD: patch-p0f.c,v 1.1 2012/03/12 13:17:22 fhajny Exp $

. More portable int types.
. More portable strstr in place of strcasestr.
. Rename 'sun' to 's_un' to avoid a conflict on SunOS.

--- p0f.c.orig	2011-03-20 09:17:09.000000000 +0000
+++ p0f.c
@@ -74,25 +74,25 @@ __RCSID("$Id: p0f.c,v 1.7.2.6 2011/03/20
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
@@ -113,7 +113,7 @@ p0f_cmp(ad, stage, ap, priv)
                return 0;
 
 	data = (char *)ad->string;
-	if (strcasestr(priv->priv_p0f, data) != NULL)
+	if (strstr(priv->priv_p0f, data) != NULL)
 		return 1;
 	return 0;
 }
@@ -262,7 +262,7 @@ p0f_sock_set(sock)
 static int
 p0f_connect(void)
 {
-	struct sockaddr_un sun;
+	struct sockaddr_un s_un;
 	int p0fsock;
 
 	if (!conf.c_p0fsock[0])
@@ -280,11 +280,11 @@ p0f_connect(void)
 
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
