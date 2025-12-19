$NetBSD: patch-src_ptp-pack.c,v 1.1 2025/12/19 11:00:46 nia Exp $

Support non-POSIX iconv in SunOS and old NetBSD.

--- src/ptp-pack.c.orig	2025-12-19 10:49:45.060422671 +0000
+++ src/ptp-pack.c
@@ -34,6 +34,15 @@
 #include <iconv.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 static inline uint16_t
 htod16p (PTPParams *params, uint16_t var)
 {
@@ -174,9 +183,14 @@ ptp_unpack_string(PTPParams *params, unsigned char* da
 	destlen = sizeof(loclstr)-1;
 	nconv = (size_t)-1;
 #if defined(HAVE_ICONV) && defined(HAVE_LANGINFO_H)
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
 	if (params->cd_ucs2_to_locale != (iconv_t)-1)
+		nconv = iconv(params->cd_ucs2_to_locale, (const char **)&src, &srclen, &dest, &destlen);
+#else
+	if (params->cd_ucs2_to_locale != (iconv_t)-1)
 		nconv = iconv(params->cd_ucs2_to_locale, &src, &srclen, &dest, &destlen);
 #endif
+#endif
 	if (nconv == (size_t) -1) { /* do it the hard way */
 		int i;
 		/* try the old way, in case iconv is broken */
@@ -224,8 +238,13 @@ ptp_pack_string(PTPParams *params, char *string, unsig
 		size_t convmax = PTP_MAXSTRLEN * 2; /* Includes the terminator */
 		char *stringp = string;
 
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+		nconv = iconv(params->cd_locale_to_ucs2, (const char **)&stringp, &convlen,
+			&ucs2strp, &convmax);
+#else
 		nconv = iconv(params->cd_locale_to_ucs2, &stringp, &convlen,
 			&ucs2strp, &convmax);
+#endif
 		if (nconv == (size_t) -1)
 			ucs2str[0] = 0x0000U;
 	} else
