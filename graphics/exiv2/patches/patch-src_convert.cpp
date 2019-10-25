$NetBSD: patch-src_convert.cpp,v 1.2 2019/10/25 09:44:26 kamil Exp $

Support NetBSD and SunOS iconv being special.

--- src/convert.cpp.orig	2019-07-29 06:33:07.000000000 +0000
+++ src/convert.cpp
@@ -1545,11 +1545,19 @@ namespace {
             char outbuf[256];
             char* outptr = outbuf;
             size_t outbytesleft = sizeof(outbuf);
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+            size_t rc = iconv(cd,
+                              const_cast<const char **>(&inptr),
+                              &inbytesleft,
+                              &outptr,
+                              &outbytesleft);
+#else
             size_t rc = iconv(cd,
                               &inptr,
                               &inbytesleft,
                               &outptr,
                               &outbytesleft);
+#endif
             const size_t outbytesProduced = sizeof(outbuf) - outbytesleft;
             if (rc == size_t(-1) && errno != E2BIG) {
 #ifndef SUPPRESS_WARNINGS
