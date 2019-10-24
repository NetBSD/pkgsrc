$NetBSD: patch-src_charset.cxx,v 1.2 2019/10/24 21:50:08 kamil Exp $

Don't strip constness for the iconv input on SunOS and old NetBSD.

--- src/charset.cxx.orig	2019-09-14 12:24:35.000000000 +0000
+++ src/charset.cxx
@@ -20,6 +20,15 @@
 #include "charset.hxx"
 #include "util/ScopeExit.hxx"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 #include <algorithm>
 
 #include <assert.h>
@@ -64,9 +73,13 @@ Iconv(iconv_t i,
 	--dest_size; /* reserve once byte for the null terminator */
 
 	while (src_length > 0) {
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+		size_t err = iconv(i, &src, &src_length, &dest, &dest_size);
+#else
 		size_t err = iconv(i,
 				   const_cast<char **>(&src), &src_length,
 				   &dest, &dest_size);
+#endif
 		if (err == (size_t)-1) {
 			switch (errno) {
 			case EILSEQ:
@@ -130,9 +143,13 @@ Iconv(iconv_t i,
 		char buffer[1024], *outbuf = buffer;
 		size_t outbytesleft = sizeof(buffer);
 
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+		size_t err = iconv(i, &src, &src_length, &outbuf, &outbytesleft);
+#else
 		size_t err = iconv(i,
 				   const_cast<char **>(&src), &src_length,
 				   &outbuf, &outbytesleft);
+#endif
 		dest.append(buffer, outbuf);
 		if (err == (size_t)-1) {
 			switch (errno) {
