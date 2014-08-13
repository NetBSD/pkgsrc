$NetBSD: patch-src_astyle__main.cpp,v 1.2 2014/08/13 21:11:07 wiz Exp $

Fix build on NetBSD.
https://sourceforge.net/p/astyle/bugs/299/

--- src/astyle_main.cpp.orig	2013-11-01 20:31:48.000000000 +0000
+++ src/astyle_main.cpp
@@ -2671,7 +2671,11 @@ utf16_t* ASLibrary::convertUtf8ToUtf16(c
 	size_t inLeft = strlen(utf8In) + 1;		// converts the ending NULL
 	char* utf16Conv = reinterpret_cast<char*>(utf16Out);
 	size_t outLeft = utf16Len;
+#ifdef __NetBSD__
+	size_t iconvval = iconv(iconvh, (const char **)&utf8Conv, &inLeft, &utf16Conv, &outLeft);
+#else
 	size_t iconvval = iconv(iconvh, &utf8Conv, &inLeft, &utf16Conv, &outLeft);
+#endif
 	///////////////////////////////////////////////////////
 	bool showStats = false;
 	if (showStats && (inLeft != 0 || outLeft != 0))
@@ -2713,7 +2717,11 @@ char* ASLibrary::convertUtf16ToUtf8(cons
 	size_t inLeft = (utf16len(utf16In) + 1) * sizeof(utf16_t);	// converts the ending NULL
 	char* utf8Conv = utf8Out;
 	size_t outLeft = utf8Len;
+#ifdef __NetBSD__
+	size_t iconvval = iconv(iconvh, (const char **)&utf16Conv, &inLeft, &utf8Conv, &outLeft);
+#else
 	size_t iconvval = iconv(iconvh, &utf16Conv, &inLeft, &utf8Conv, &outLeft);
+#endif
 	///////////////////////////////////////////////////////
 	bool showStats = false;
 	if (showStats && (inLeft != 0 || outLeft != 0))
