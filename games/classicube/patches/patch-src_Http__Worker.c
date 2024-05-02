$NetBSD: patch-src_Http__Worker.c,v 1.1 2024/05/02 07:33:19 nia Exp $

Get rid of hardcoded paths and shlib versions.

--- src/Http_Worker.c.orig	2024-05-02 07:25:05.547759016 +0000
+++ src/Http_Worker.c
@@ -259,18 +259,9 @@ static const cc_string curlAlt = String_
 #elif defined CC_BUILD_DARWIN
 static const cc_string curlLib = String_FromConst("libcurl.4.dylib");
 static const cc_string curlAlt = String_FromConst("libcurl.dylib");
-#elif defined CC_BUILD_NETBSD
-static const cc_string curlLib = String_FromConst("libcurl.so");
-static const cc_string curlAlt = String_FromConst("/usr/pkg/lib/libcurl.so");
-#elif defined CC_BUILD_BSD
+#else
 static const cc_string curlLib = String_FromConst("libcurl.so");
 static const cc_string curlAlt = String_FromConst("libcurl.so");
-#elif defined CC_BUILD_SERENITY
-static const cc_string curlLib = String_FromConst("/usr/local/lib/libcurl.so");
-static const cc_string curlAlt = String_FromConst("/usr/local/lib/libcurl.so");
-#else
-static const cc_string curlLib = String_FromConst("libcurl.so.4");
-static const cc_string curlAlt = String_FromConst("libcurl.so.3");
 #endif
 
 static cc_bool LoadCurlFuncs(void) {
@@ -1525,4 +1516,4 @@ static void Http_Init(void) {
 
 	Thread_Start2(workerThread, WorkerLoop);
 }
-#endif
\ No newline at end of file
+#endif
