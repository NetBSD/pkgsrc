$NetBSD: patch-libqalculate_util.cc,v 1.2 2019/12/09 09:31:06 nros Exp $
* use ICONV_CONST from autotools to support const char**
* applied upstream https://github.com/Qalculate/libqalculate/pull/168
--- libqalculate/util.cc.orig	2019-12-08 21:53:48.021366402 +0000
+++ libqalculate/util.cc
@@ -706,7 +706,7 @@ char *locale_from_utf8(const char *str) 
 	char *dest, *buffer;
 	buffer = dest = (char*) malloc((outlength + 4) * sizeof(char));
 	if(!buffer) return NULL;
-	size_t err = iconv(conv, (char **) &str, &inlength, &buffer, &outlength);
+	size_t err = iconv(conv, (ICONV_CONST char **) &str, &inlength, &buffer, &outlength);
 	if(err != (size_t) -1) err = iconv(conv, NULL, &inlength, &buffer, &outlength);
 	iconv_close(conv);
 	memset(buffer, 0, 4);
@@ -721,7 +721,7 @@ char *locale_to_utf8(const char *str) {
 	char *dest, *buffer;
 	buffer = dest = (char*) malloc((outlength + 4) * sizeof(char));
 	if(!buffer) return NULL;
-	size_t err = iconv(conv, (char**) &str, &inlength, &buffer, &outlength);
+	size_t err = iconv(conv, (ICONV_CONST char**) &str, &inlength, &buffer, &outlength);
 	if(err != (size_t) -1) err = iconv(conv, NULL, &inlength, &buffer, &outlength);
 	iconv_close(conv);
 	memset(buffer, 0, 4 * sizeof(char));
