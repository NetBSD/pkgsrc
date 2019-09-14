$NetBSD: patch-src_charset.cxx,v 1.1 2019/09/14 12:19:40 nia Exp $

Don't strip constness for the iconv input on SunOS and NetBSD,
which continue to have the input as const.

--- src/charset.cxx.orig	2019-04-10 09:08:34.000000000 +0000
+++ src/charset.cxx
@@ -64,9 +64,13 @@ Iconv(iconv_t i,
 	--dest_size; /* reserve once byte for the null terminator */
 
 	while (src_length > 0) {
+#if !defined(__NetBSD__) && !defined(__sun)
 		size_t err = iconv(i,
 				   const_cast<char **>(&src), &src_length,
 				   &dest, &dest_size);
+#else
+		size_t err = iconv(i, &src, &src_length, &dest, &dest_size);
+#endif
 		if (err == (size_t)-1) {
 			switch (errno) {
 			case EILSEQ:
@@ -130,9 +134,13 @@ Iconv(iconv_t i,
 		char buffer[1024], *outbuf = buffer;
 		size_t outbytesleft = sizeof(buffer);
 
+#if !defined(__NetBSD__) && !defined(__sun)
 		size_t err = iconv(i,
 				   const_cast<char **>(&src), &src_length,
 				   &outbuf, &outbytesleft);
+#else
+		size_t err = iconv(i, &src, &src_length, &outbuf, &outbytesleft);
+#endif
 		dest.append(buffer, outbuf);
 		if (err == (size_t)-1) {
 			switch (errno) {
