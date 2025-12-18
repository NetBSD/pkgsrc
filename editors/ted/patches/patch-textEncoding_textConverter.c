$NetBSD: patch-textEncoding_textConverter.c,v 1.1 2025/12/18 09:14:40 nia Exp $

Support non-POSIX iconv in SunOS and old NetBSD.

--- textEncoding/textConverter.c.orig	2025-12-18 08:30:05.458713346 +0000
+++ textEncoding/textConverter.c
@@ -20,6 +20,15 @@
 #   include	"uniLegacyEncoding.h"
 #   include	"uniLegacyMapping.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 void textConverterSetNativeEncodingName(	TextConverter *	tc,
 						const char *	encodingName )
     {
@@ -265,7 +274,11 @@ static int textConverterConvertIconv(	TextConverter *	
 	    /*  return value is irrelevant: Just tells that the	*/
 	    /*  conversion was incomplete. So does ileft > 0.	*/
 
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+	    (void)iconv( ico, (const char **)&ibuf, &ileft, &obuf, &oleft );
+#else
 	    (void)iconv( ico, &ibuf, &ileft, &obuf, &oleft );
+#endif
 
 	    if  ( ibuf == iibuf )
 		{ /*XXDEB(ibuf,iibuf);*/ break;	}
