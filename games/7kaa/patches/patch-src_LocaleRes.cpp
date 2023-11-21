$NetBSD: patch-src_LocaleRes.cpp,v 1.5 2023/11/21 13:58:03 nia Exp $

Support NetBSD and SunOS iconv being special.

--- src/LocaleRes.cpp.orig	2023-07-24 23:02:38.000000000 +0000
+++ src/LocaleRes.cpp
@@ -31,6 +31,14 @@
 #include <ODB.h>
 #include <LocaleRes.h>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
 
 #ifndef HAVE_SETENV
 static String lc_all_str;
@@ -226,7 +234,11 @@ const char *LocaleRes::conv_str(iconv_t 
 	size_t c;
 	while( in_left>0 )
 	{
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+		c = iconv(cd, (const char **)&p1, &in_left, &p2, &out_left);
+#else
 		c = iconv(cd, &p1, &in_left, &p2, &out_left);
+#endif
 		if( c == (size_t)-1 )
 			return s;
 		if( in_left )
