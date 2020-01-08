$NetBSD: patch-src_LocaleRes.cpp,v 1.4 2020/01/08 16:59:07 nia Exp $

Support NetBSD and SunOS iconv being special.

--- src/LocaleRes.cpp.orig	2019-12-22 22:27:28.000000000 +0000
+++ src/LocaleRes.cpp
@@ -31,6 +31,15 @@
 #include <ConfigAdv.h>
 #include <LocaleRes.h>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 //------------- End of function Constructor -------//
 //
 LocaleRes::LocaleRes()
@@ -191,7 +200,11 @@ const char *LocaleRes::conv_str(iconv_t 
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
