$NetBSD: patch-utf8.h,v 1.1 2012/03/12 13:29:20 fhajny Exp $

Remove stale C++ conditionals.
--- utf8.h.orig	2011-01-26 10:36:21.000000000 +0000
+++ utf8.h
@@ -27,13 +27,8 @@
 #define UTF8_IGNORE_ERROR		0x01
 #define UTF8_SKIP_BOM			0x02
 
-__BEGIN_DECLS
-
 size_t		utf8_to_wchar(const char *in, size_t insize, wchar_t *out,
 		    size_t outsize, int flags);
 size_t		wchar_to_utf8(const wchar_t *in, size_t insize, char *out,
 		    size_t outsize, int flags);
-
-__END_DECLS
-
 #endif /* !_UTF8_H_ */
