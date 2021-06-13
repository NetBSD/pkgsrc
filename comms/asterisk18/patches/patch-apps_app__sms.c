$NetBSD: patch-apps_app__sms.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- apps/app_sms.c.orig	2018-05-01 20:12:26.000000000 +0000
+++ apps/app_sms.c
@@ -291,7 +291,7 @@ static void numcpy(char *d, char *s)
 		*d++ = *s++;
 	}
 	while (*s) {
-  		if (isdigit(*s)) {
+  		if (isdigit((unsigned char)*s)) {
 			*d++ = *s;
 		}
 		s++;
@@ -557,7 +557,7 @@ static void packdate(unsigned char *o, t
 	int z;
 
 	ast_localtime(&topack, &t, NULL);
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined( __NetBSD__ ) || defined(__APPLE__) || defined(__CYGWIN__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined( __NetBSD__ ) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__DragonFly__)
 	z = -t.tm_gmtoff / 60 / 15;
 #else
 	z = timezone / 60 / 15;
@@ -754,7 +754,7 @@ static unsigned char packaddress(unsigne
 		o[1] = 0x81;
 	}
 	for ( ; *i ; i++) {
-		if (!isdigit(*i)) {                 /* ignore non-digits */
+		if (!isdigit((unsigned char)*i)) {                 /* ignore non-digits */
 			continue;
 		}
 		if (o[0] & 1) {
@@ -849,11 +849,11 @@ static void sms_readfile(sms_t * h, char
 			if (!*p || *p == ';') {
 				continue;                   /* blank line or comment, ignore */
 			}
-			while (isalnum(*p)) {
-				*p = tolower (*p);
+			while (isalnum((unsigned char)*p)) {
+				*p = tolower ((unsigned char)*p);
 				p++;
 			}
-			while (isspace (*p)) {
+			while (isspace ((unsigned char)*p)) {
 				*p++ = 0;
 			}
 			if (*p == '=') {
@@ -869,7 +869,7 @@ static void sms_readfile(sms_t * h, char
 						ast_log(LOG_WARNING, "UD too long in %s\n", fn);
 					}
 				} else {
-					while (isspace (*p)) {
+					while (isspace ((unsigned char)*p)) {
 						p++;
 					}
 					if (!strcmp(line, "oa") && strlen(p) < sizeof(h->oa)) {
@@ -917,11 +917,11 @@ static void sms_readfile(sms_t * h, char
 					if (!strcmp(line, "ud")) {        /* user data */
 						int o = 0;
 						while (*p && o < SMSLEN) {
-							if (isxdigit(*p) && isxdigit(p[1]) && isxdigit(p[2]) && isxdigit(p[3])) {
+							if (isxdigit((unsigned char)*p) && isxdigit((unsigned char)p[1]) && isxdigit((unsigned char)p[2]) && isxdigit((unsigned char)p[3])) {
 								h->ud[o++] =
-									(((isalpha(*p) ? 9 : 0) + (*p & 0xF)) << 12) +
-									(((isalpha(p[1]) ? 9 : 0) + (p[1] & 0xF)) << 8) +
-									(((isalpha(p[2]) ? 9 : 0) + (p[2] & 0xF)) << 4) + ((isalpha(p[3]) ? 9 : 0) + (p[3] & 0xF));
+									(((isalpha((unsigned char)*p) ? 9 : 0) + (*p & 0xF)) << 12) +
+									(((isalpha((unsigned char)p[1]) ? 9 : 0) + (p[1] & 0xF)) << 8) +
+									(((isalpha((unsigned char)p[2]) ? 9 : 0) + (p[2] & 0xF)) << 4) + ((isalpha((unsigned char)p[3]) ? 9 : 0) + (p[3] & 0xF));
 								p += 4;
 							} else
 								break;
@@ -934,8 +934,8 @@ static void sms_readfile(sms_t * h, char
 				} else if (!strcmp(line, "ud")) {       /* user data */
 					int o = 0;
 					while (*p && o < SMSLEN) {
-						if (isxdigit(*p) && isxdigit(p[1])) {
-							h->ud[o++] = (((isalpha(*p) ? 9 : 0) + (*p & 0xF)) << 4) + ((isalpha(p[1]) ? 9 : 0) + (p[1] & 0xF));
+						if (isxdigit((unsigned char)*p) && isxdigit((unsigned char)p[1])) {
+							h->ud[o++] = (((isalpha((unsigned char)*p) ? 9 : 0) + (*p & 0xF)) << 4) + ((isalpha((unsigned char)p[1]) ? 9 : 0) + (p[1] & 0xF));
 							p += 2;
 						} else {
 							break;
@@ -949,8 +949,8 @@ static void sms_readfile(sms_t * h, char
 					unsigned char o = 0;
 					h->udhi = 1;
 					while (*p && o < SMSLEN) {
-						if (isxdigit(*p) && isxdigit(p[1])) {
-							h->udh[o] = (((isalpha(*p) ? 9 : 0) + (*p & 0xF)) << 4) + ((isalpha(p[1]) ? 9 : 0) + (p[1] & 0xF));
+						if (isxdigit((unsigned char)*p) && isxdigit((unsigned char)p[1])) {
+							h->udh[o] = (((isalpha((unsigned char)*p) ? 9 : 0) + (*p & 0xF)) << 4) + ((isalpha((unsigned char)p[1]) ? 9 : 0) + (p[1] & 0xF));
 							o++;
 							p += 2;
 						} else {
@@ -1928,7 +1928,7 @@ static int sms_exec(struct ast_channel *
 	ast_copy_string(h.queue, sms_args.queue, sizeof(h.queue));
 
 	for (p = h.queue; *p; p++) {
-		if (!isalnum(*p)) {
+		if (!isalnum((unsigned char)*p)) {
 			*p = '-';                       /* make very safe for filenames */
 		}
 	}
