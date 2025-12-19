$NetBSD: patch-src_unicode.c,v 1.1 2025/12/19 11:00:46 nia Exp $

Support non-POSIX iconv in SunOS and old NetBSD.

--- src/unicode.c.orig	2025-12-19 10:50:53.932872746 +0000
+++ src/unicode.c
@@ -41,6 +41,15 @@
 #include "util.h"
 #include "ptp.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 /**
  * The size of the buffer (in characters) used for creating string copies.
  */
@@ -81,7 +90,11 @@ char *utf16_to_utf8(LIBMTP_mtpdevice_t *device, const 
   loclstr[0]='\0';
   #if defined(HAVE_ICONV) && defined(HAVE_LANGINFO_H)
   PTPParams *params = (PTPParams *) device->params;
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+  const char *stringp = (const char *) unicstr;
+#else
   char *stringp = (char *) unicstr;
+#endif
   char *locp = loclstr;
   size_t nconv;
   size_t convlen = (ucs2_strlen(unicstr)+1) * sizeof(uint16_t); // UCS-2 is 16 bit wide, include terminator
@@ -120,7 +133,11 @@ uint16_t *utf8_to_utf16(LIBMTP_mtpdevice_t *device, co
 
   #if defined(HAVE_ICONV) && defined(HAVE_LANGINFO_H)
   PTPParams *params = (PTPParams *) device->params;
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+  const char *stringp = (const char *) localstr;
+#else
   char *stringp = (char *) localstr; // cast away "const"
+#endif
   size_t convlen = strlen(localstr)+1; // utf8 bytes, include terminator
   size_t convmax = STRING_BUFFER_LENGTH*2;
   /* Do the conversion.  */
