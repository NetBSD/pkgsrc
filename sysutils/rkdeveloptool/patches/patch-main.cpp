$NetBSD: patch-main.cpp,v 1.1 2018/08/31 10:09:51 tnn Exp $

match iconv(3) prototype

--- main.cpp.orig	2018-03-28 01:22:40.000000000 +0000
+++ main.cpp
@@ -168,7 +168,7 @@ bool StringToWideString(char *pszSrc, wc
 	pIn = (char *)pszSrc;
 	pOut = (char *)pszDest;
 
-	iRet = iconv(cd, (char **)&pIn, (size_t *)&nSrcLen, (char **)&pOut, (size_t *)&nDestLen);
+	iRet = iconv(cd, (const char **)&pIn, (size_t *)&nSrcLen, (char **)&pOut, (size_t *)&nDestLen);
 
 	if(iRet == -1) {
 		delete []pszDest;
@@ -205,7 +205,7 @@ bool WideStringToString(wchar_t *pszSrc,
 	char *pIn, *pOut;
 	pIn = (char *)pszSrc;
 	pOut = (char *)pszDest;
-	iRet = iconv(cd, (char **)&pIn, (size_t *)&nSrcLen, (char **)&pOut, (size_t *)&nDestLen);
+	iRet = iconv(cd, (const char **)&pIn, (size_t *)&nSrcLen, (char **)&pOut, (size_t *)&nDestLen);
 
 	if(iRet == -1) {
 		delete []pszDest;
