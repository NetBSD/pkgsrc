$NetBSD: patch-mozilla_xpcom_glue_standalone_nsXPCOMGlue.cpp,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/xpcom/glue/standalone/nsXPCOMGlue.cpp.orig	2015-06-08 17:49:33.000000000 +0000
+++ mozilla/xpcom/glue/standalone/nsXPCOMGlue.cpp
@@ -30,7 +30,7 @@ static bool do_preload = false;
 #endif
 
 #if defined(SUNOS4) || defined(NEXTSTEP) || \
-    defined(XP_DARWIN) || \
+    defined(XP_MACOSX) || \
     (defined(OPENBSD) || defined(NETBSD)) && !defined(__ELF__)
 #define LEADING_UNDERSCORE "_"
 #else
