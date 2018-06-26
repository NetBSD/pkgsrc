$NetBSD: patch-src_common_system__signal__handling.c,v 1.1 2018/06/26 10:49:11 jperkin Exp $

Fix build on SunOS.

--- src/common/system_signal_handling.c.orig	2017-05-28 14:22:21.000000000 +0000
+++ src/common/system_signal_handling.c
@@ -69,7 +69,11 @@ static dt_signal_handler_t *_orig_sig_ha
 
 #if(defined(__FreeBSD_version) && (__FreeBSD_version < 800071)) || (defined(OpenBSD) && (OpenBSD < 201305))       \
     || defined(__SUNOS__)
+#ifdef __sun
+static int dprintf(int fd, const char *fmt, ...)
+#else
 static int dprintf(int fd, const char *fmt, ...) __attribute__((format(printf, 2, 3)))
+#endif
 {
   va_list ap;
   FILE *f = fdopen(fd, "a");
