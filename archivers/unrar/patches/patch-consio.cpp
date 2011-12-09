$NetBSD: patch-consio.cpp,v 1.1 2011/12/09 13:51:56 hans Exp $

Use getpassphrase(3C) on SunOS to allow passwords longer than 8 chars.

--- consio.cpp.orig	2011-03-02 08:43:12.000000000 +0100
+++ consio.cpp	2011-12-09 14:38:05.903683508 +0100
@@ -129,6 +129,8 @@ void GetPasswordText(wchar *Str,uint Max
   char StrA[MAXPASSWORD];
 #if defined(_EMX) || defined(_BEOS) || defined(__sparc) || defined(sparc) || defined (__VMS)
   fgets(StrA,ASIZE(StrA)-1,stdin);
+#elif defined(__sun)
+  strncpyz(StrA,getpassphrase(""),ASIZE(StrA));
 #else
   strncpyz(StrA,getpass(""),ASIZE(StrA));
 #endif
