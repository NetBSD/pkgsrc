$NetBSD: patch-prnt_hpijs_context2.cpp,v 1.1 2012/06/23 04:50:07 schnoebe Exp $

use strlen(3) instead of strnlen(3), for use on NetBSD 4.0 and earlier
as well as other systems that don't have strnlen.

Ideally, the configure script would check for strnlen, and include a
replacement  implementation if required.

--- prnt/hpijs/context2.cpp.orig	2012-06-05 09:27:40.000000000 +0000
+++ prnt/hpijs/context2.cpp
@@ -1299,7 +1299,11 @@ DRIVER_ERROR PrintContext::SelectDevice
     {
         return UNSUPPORTED_PRINTER;
     }
-	if(0 == strnlen((const char *)pSS->strDevID, DevIDBuffSize))
+
+	/* make sure a trailing zero/null exists in the string */
+	pSS->strDevID[(DevIDBuffSize - 1)] = 0;
+
+	if(0 == strlen((const char *)pSS->strDevID))
 	{
 		strncpy((char *)pSS->strDevID,szDeviceId,DevIDBuffSize);
 	}
