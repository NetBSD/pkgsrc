$NetBSD: patch-src_pcre2posix.h,v 1.1 2022/12/08 10:30:48 adam Exp $

Fix for https://github.com/PCRE2Project/pcre2/issues/173

--- src/pcre2posix.h.orig	2022-12-08 10:20:30.000000000 +0000
+++ src/pcre2posix.h
@@ -144,6 +144,10 @@ regex functions. It's done this way to e
 the PCRE2 library and not by accident from elsewhere (regex_t differs in size
 elsewhere). */
 
+#ifndef PCRE2_CALL_CONVENTION
+#define PCRE2_CALL_CONVENTION
+#endif
+
 PCRE2POSIX_EXP_DECL int PCRE2_CALL_CONVENTION pcre2_regcomp(regex_t *, const char *, int);
 PCRE2POSIX_EXP_DECL int PCRE2_CALL_CONVENTION pcre2_regexec(const regex_t *, const char *, size_t,
                      regmatch_t *, int);
