$NetBSD: patch-string_func.h,v 1.1 2009/09/22 12:02:36 ahoka Exp $

--- src/string_func.h.orig	2009-05-10 23:33:55.000000000 +0200
+++ src/string_func.h
@@ -239,13 +239,13 @@ static inline bool IsWhitespace(WChar c)
 	;
 }
 
-#ifndef _GNU_SOURCE
+#if !defined(_GNU_SOURCE) && (defined(__NetBSD_Version__) && __NetBSD_Version__ < 500000000)
 /* strndup is a GNU extension */
 char *strndup(const char *s, size_t len);
 #endif /* !_GNU_SOURCE */
 
 /* strcasestr is available for _GNU_SOURCE, BSD and some Apple */
-#if defined(_GNU_SOURCE) || (defined(__BSD_VISIBLE) && __BSD_VISIBLE) || (defined(__APPLE__) && (!defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)))
+#if defined(_GNU_SOURCE) || (defined(__BSD_VISIBLE) && __BSD_VISIBLE) || (defined(__APPLE__) && (!defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE))) || defined(_NETBSD_SOURCE)
 #	undef DEFINE_STRCASESTR
 #else
 #	define DEFINE_STRCASESTR
