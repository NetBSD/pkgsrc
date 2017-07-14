$NetBSD: patch-src_be13__api_beregex.cpp,v 1.1 2017/07/14 12:58:25 joerg Exp $

--- src/be13_api/beregex.cpp.orig	2017-07-12 22:51:30.689369147 +0000
+++ src/be13_api/beregex.cpp
@@ -9,7 +9,7 @@
 #include <unistd.h>
 
 
-#if defined(HAVE_LIBTRE) && defined(HAVE_TRE_REGCOMP)
+#if defined(HAVE_LIBTRE) && defined(HAVE_TRE_REGCOMP) && defined(HAVE_TRE_TRE_H)
 #define REGCOMP tre_regcomp
 #define REGFREE tre_regfree
 #define REGEXEC tre_regexec
