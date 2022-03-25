$NetBSD: patch-src_utils.cpp,v 1.2 2022/03/25 10:37:30 wiz Exp $

Adapt to NetBSD iconv prototype change.

--- src/utils.cpp.orig	2015-02-19 10:56:59.000000000 +0000
+++ src/utils.cpp
@@ -37,6 +37,13 @@ GCRY_THREAD_OPTION_PTHREAD_IMPL;
 #include <openssl/crypto.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#endif
+#endif
+
 namespace newsbeuter {
 
 std::vector<std::string> utils::tokenize_quoted(const std::string& str, std::string delimiters) {
@@ -274,7 +281,7 @@ std::string utils::convert_text(const st
 	 * of all the Unix-like systems around there, only Linux/glibc seems to
 	 * come with a SuSv3-conforming iconv implementation.
 	 */
-#if !(__linux) && !defined(__GLIBC__) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if !(__linux) && !defined(__GLIBC__) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(NETBSD_POSIX_ICONV)
 	const char * inbufp;
 #else
 	char * inbufp;
