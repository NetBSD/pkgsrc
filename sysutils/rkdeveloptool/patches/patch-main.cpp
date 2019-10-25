$NetBSD: patch-main.cpp,v 1.2 2019/10/25 10:10:10 kamil Exp $

match iconv(3) prototype

--- main.cpp.orig	2018-03-28 01:22:40.000000000 +0000
+++ main.cpp
@@ -15,6 +15,16 @@
 #include "RKComm.h"
 #include "RKDevice.h"
 #include "RKImage.h"
+
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 extern const char *szManufName[];
 CRKLog *g_pLogObject=NULL;
 CONFIG_ITEM_VECTOR g_ConfigItemVec;
@@ -168,7 +178,11 @@ bool StringToWideString(char *pszSrc, wc
 	pIn = (char *)pszSrc;
 	pOut = (char *)pszDest;
 
-	iRet = iconv(cd, (char **)&pIn, (size_t *)&nSrcLen, (char **)&pOut, (size_t *)&nDestLen);
+#if defined(__NetBSD__) && !NETBSD_POSIX_ICONV
+	iRet = iconv(cd, (const char **)&pIn, (size_t *)&nSrcLen, (char **)&pOut, (size_t *)&nDestLen);
+#else
+	iRet = iconv(cd, &pIn, (size_t *)&nSrcLen, (char **)&pOut, (size_t *)&nDestLen);
+#endif
 
 	if(iRet == -1) {
 		delete []pszDest;
@@ -205,7 +219,11 @@ bool WideStringToString(wchar_t *pszSrc,
 	char *pIn, *pOut;
 	pIn = (char *)pszSrc;
 	pOut = (char *)pszDest;
+#if defined(__NetBSD__) && !NETBSD_POSIX_ICONV
+	iRet = iconv(cd, (const char **)&pIn, (size_t *)&nSrcLen, (char **)&pOut, (size_t *)&nDestLen);
+#else
 	iRet = iconv(cd, (char **)&pIn, (size_t *)&nSrcLen, (char **)&pOut, (size_t *)&nDestLen);
+#endif
 
 	if(iRet == -1) {
 		delete []pszDest;
