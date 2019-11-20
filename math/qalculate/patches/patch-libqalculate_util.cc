$NetBSD: patch-libqalculate_util.cc,v 1.1 2019/11/20 22:15:28 markd Exp $

Support NetBSD iconv variant (pre-9.99.17 and newer)

--- libqalculate/util.cc.orig	2019-07-21 07:29:17.000000000 +0000
+++ libqalculate/util.cc
@@ -20,6 +20,9 @@
 #include <iconv.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
 #include <sstream>
 #include <fstream>
 #ifdef HAVE_LIBCURL
@@ -686,6 +689,12 @@ bool removeDir(string dirpath) {
 #endif
 }
 
+#if defined(__NetBSD__) && __NetBSD_Version__ < 999001700
+#define ICONV_CHAR_TYPE const char **
+#else
+#define ICONV_CHAR_TYPE char **
+#endif
+
 char *locale_from_utf8(const char *str) {
 	iconv_t conv = iconv_open("", "UTF-8");
 	if(conv == (iconv_t) -1) return NULL;
@@ -694,7 +703,7 @@ char *locale_from_utf8(const char *str) 
 	char *dest, *buffer;
 	buffer = dest = (char*) malloc((outlength + 4) * sizeof(char));
 	if(!buffer) return NULL;
-	size_t err = iconv(conv, (char **) &str, &inlength, &buffer, &outlength);
+	size_t err = iconv(conv, (ICONV_CHAR_TYPE) &str, &inlength, &buffer, &outlength);
 	if(err != (size_t) -1) err = iconv(conv, NULL, &inlength, &buffer, &outlength);
 	iconv_close(conv);
 	memset(buffer, 0, 4);
@@ -709,7 +718,7 @@ char *locale_to_utf8(const char *str) {
 	char *dest, *buffer;
 	buffer = dest = (char*) malloc((outlength + 4) * sizeof(char));
 	if(!buffer) return NULL;
-	size_t err = iconv(conv, (char**) &str, &inlength, &buffer, &outlength);
+	size_t err = iconv(conv, (ICONV_CHAR_TYPE) &str, &inlength, &buffer, &outlength);
 	if(err != (size_t) -1) err = iconv(conv, NULL, &inlength, &buffer, &outlength);
 	iconv_close(conv);
 	memset(buffer, 0, 4 * sizeof(char));
