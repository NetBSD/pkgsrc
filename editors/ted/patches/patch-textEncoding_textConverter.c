$NetBSD: patch-textEncoding_textConverter.c,v 1.2 2026/06/18 14:56:55 nia Exp $

Support non-POSIX iconv in SunOS and old NetBSD.

Making sure to carefully handle the case of an external iconv being
pulled in from GNU libiconv.

--- textEncoding/textConverter.c.orig	2013-02-01 12:11:08.000000000 +0000
+++ textEncoding/textConverter.c
@@ -20,6 +20,13 @@
 #   include	"uniLegacyEncoding.h"
 #   include	"uniLegacyMapping.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#endif
+#endif
+
 void textConverterSetNativeEncodingName(	TextConverter *	tc,
 						const char *	encodingName )
     {
@@ -265,7 +272,11 @@ static int textConverterConvertIconv(	TextConverter *	
 	    /*  return value is irrelevant: Just tells that the	*/
 	    /*  conversion was incomplete. So does ileft > 0.	*/
 
+#if (defined(__NetBSD__) || defined(__sun)) && !defined(NETBSD_POSIX_ICONV) && !defined(_LIBICONV_VERSION)
+	    (void)iconv( ico, (const char **)&ibuf, &ileft, &obuf, &oleft );
+#else
 	    (void)iconv( ico, &ibuf, &ileft, &obuf, &oleft );
+#endif
 
 	    if  ( ibuf == iibuf )
 		{ /*XXDEB(ibuf,iibuf);*/ break;	}
