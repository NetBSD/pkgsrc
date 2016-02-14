$NetBSD: patch-xpcom_glue_standalone_nsXPCOMGlue.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

Fix inconsistent use of XP_DARWIN and XP_MACOSX: LEADING_UNDERSCORE
should be empty when we are going to load XPCOM using dlopen(3), not
NSAddImage().

--- xpcom/glue/standalone/nsXPCOMGlue.cpp.orig	2015-01-30 05:17:58.000000000 +0000
+++ xpcom/glue/standalone/nsXPCOMGlue.cpp
@@ -30,7 +30,7 @@ static bool do_preload = false;
 #endif
 
 #if defined(SUNOS4) || defined(NEXTSTEP) || \
-    defined(XP_DARWIN) || \
+    defined(XP_MACOSX) || \
     (defined(OPENBSD) || defined(NETBSD)) && !defined(__ELF__)
 #define LEADING_UNDERSCORE "_"
 #else
