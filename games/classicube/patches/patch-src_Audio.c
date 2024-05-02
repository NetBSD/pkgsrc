$NetBSD: patch-src_Audio.c,v 1.1 2024/05/02 07:33:19 nia Exp $

Get rid of hardcoded paths and shlib versions.

--- src/Audio.c.orig	2024-05-02 07:24:35.354685882 +0000
+++ src/Audio.c
@@ -124,12 +124,8 @@ static const cc_string alLib = String_Fr
 static const cc_string alLib = String_FromConst("/System/Library/Frameworks/OpenAL.framework/Versions/A/OpenAL");
 #elif defined CC_BUILD_IOS
 static const cc_string alLib = String_FromConst("/System/Library/Frameworks/OpenAL.framework/OpenAL");
-#elif defined CC_BUILD_NETBSD
-static const cc_string alLib = String_FromConst("/usr/pkg/lib/libopenal.so");
-#elif defined CC_BUILD_BSD
-static const cc_string alLib = String_FromConst("libopenal.so");
 #else
-static const cc_string alLib = String_FromConst("libopenal.so.1");
+static const cc_string alLib = String_FromConst("libopenal.so");
 #endif
 
 static cc_bool LoadALFuncs(void) {
@@ -1523,4 +1519,4 @@ static void OnFree(void) {
 struct IGameComponent Audio_Component = {
 	OnInit, /* Init  */
 	OnFree  /* Free  */
-};
\ No newline at end of file
+};
