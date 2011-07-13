$NetBSD: patch-util_scan_scan.c,v 1.1.1.1 2011/07/13 23:42:16 jmcneill Exp $

--- util/scan/scan.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ util/scan/scan.c
@@ -36,8 +36,12 @@
 #include <iconv.h>
 #include <langinfo.h>
 
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/frontend.h>
 #include <linux/dvb/dmx.h>
+#endif
 
 #include "list.h"
 #include "diseqc.h"
@@ -71,7 +75,11 @@ static int unique_anon_services;
 
 char *default_charset = "ISO-6937";
 char *output_charset;
+#ifdef __NetBSD__
+#define CS_OPTIONS ""
+#else
 #define CS_OPTIONS "//TRANSLIT"
+#endif
 
 static enum fe_spectral_inversion spectral_inversion = INVERSION_AUTO;
 
@@ -1455,7 +1463,7 @@ static void parse_psip_vct (const unsign
 		if (s->service_name)
 			free(s->service_name);
 
-		s->service_name = malloc(7*sizeof(unsigned char));
+		s->service_name = malloc(8*sizeof(unsigned char));
 		/* TODO find a better solution to convert UTF-16 */
 		s->service_name[0] = ch.short_name0;
 		s->service_name[1] = ch.short_name1;
@@ -1464,6 +1472,7 @@ static void parse_psip_vct (const unsign
 		s->service_name[4] = ch.short_name4;
 		s->service_name[5] = ch.short_name5;
 		s->service_name[6] = ch.short_name6;
+		s->service_name[7] = '\0';
 
 		parse_psip_descriptors(s,&b[32],ch.descriptors_length);
 
