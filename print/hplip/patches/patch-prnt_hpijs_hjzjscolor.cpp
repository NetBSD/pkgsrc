$NetBSD: patch-prnt_hpijs_hjzjscolor.cpp,v 1.1 2012/06/23 04:50:07 schnoebe Exp $

use strlen(3) instead of strnlen(3), for use on NetBSD 4.0 and earlier
as well as other systems that don't have strnlen.

Ideally, the configure script would check for strnlen, and include a
replacement  implementation if required.

--- prnt/hpijs/ljzjscolor.cpp.orig	2012-06-05 09:34:13.000000000 +0000
+++ prnt/hpijs/ljzjscolor.cpp
@@ -522,11 +522,13 @@ bool LJZjsColor::IsLJZjsColor2Printer(Sy
 	DRIVER_ERROR err;
 	bool bLJZjsColor2Printer = FALSE;
 	err = pSS->GetDeviceID(strDeviceID,DevIDBuffSize,FALSE);
+	/* make sure there is a NULL terminator on the string */
+	strDeviceID[(DevIDBuffSize - 1)] = 0;
 
 	for(int i=0; i< LJZJSCOLOR2DEVICESCOUNT; i++)
 	{
 		if( NO_ERROR == err &&
-			(strnlen((const char*)strDeviceID, DevIDBuffSize)< DevIDBuffSize) && 
+			(strlen((const char*)strDeviceID) < DevIDBuffSize) && 
 			(strstr((const char*)strDeviceID, (const char*)szLJZjsColor2ModelNames[i])))
 		{
 			bLJZjsColor2Printer = TRUE;
