$NetBSD: patch-src_Platform__Posix.c,v 1.1 2024/05/02 07:33:20 nia Exp $

Get rid of hardcoded paths.

--- src/Platform_Posix.c.orig	2024-05-02 07:23:04.808912388 +0000
+++ src/Platform_Posix.c
@@ -478,15 +478,13 @@ void Platform_LoadSysFonts(void) { 
 	};
 #elif defined CC_BUILD_NETBSD
 	static const cc_string dirs[] = {
-		String_FromConst("/usr/X11R7/lib/X11/fonts"),
-		String_FromConst("/usr/pkg/lib/X11/fonts"),
-		String_FromConst("/usr/pkg/share/fonts")
+		String_FromConst("@X11BASE@/lib/X11/fonts"),
+		String_FromConst("@PREFIX@/share/fonts")
 	};
 #elif defined CC_BUILD_OPENBSD
 	static const cc_string dirs[] = {
-		String_FromConst("/usr/X11R6/lib/X11/fonts"),
-		String_FromConst("/usr/share/fonts"),
-		String_FromConst("/usr/local/share/fonts")
+		String_FromConst("@X11BASE@/lib/X11/fonts"),
+		String_FromConst("@PREFIX@/share/fonts"),
 	};
 #elif defined CC_BUILD_HAIKU
 	static const cc_string dirs[] = {
@@ -507,8 +505,8 @@ void Platform_LoadSysFonts(void) { 
 	};
 #else
 	static const cc_string dirs[] = {
-		String_FromConst("/usr/share/fonts"),
-		String_FromConst("/usr/local/share/fonts")
+		String_FromConst("@X11BASE@/lib/X11/fonts"),
+		String_FromConst("@PREFIX@/share/fonts"),
 	};
 #endif
 	for (i = 0; i < Array_Elems(dirs); i++) {
