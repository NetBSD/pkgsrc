$NetBSD: patch-src_base_i18n.h,v 1.1 2024/11/18 07:58:49 wiz Exp $

Define gettext_noop if missing.

Fixed in upstream head with migration to tinygettext.

--- src/base/i18n.h.orig	2024-03-28 10:12:05.000000000 +0000
+++ src/base/i18n.h
@@ -52,6 +52,10 @@
 #define npgettext(c, s, p, n) i18n::npgettext_wrapper(c, s, p, n)
 #endif
 
+#ifndef gettext_noop
+#define gettext_noop(str) (str)
+#endif
+
 namespace i18n {
 
 // Make every call to translate log the string for debugging.
@@ -59,9 +63,9 @@ void enable_verbose_i18n();
 
 char const* translate(char const*) __attribute__((format_arg(1)));
 char const* translate(const std::string&);
-char const* ngettext_wrapper(const char* singular, const char* plural, int n);
-char const* pgettext_wrapper(const char* msgctxt, const char* msgid);
-char const* npgettext_wrapper(const char* msgctxt, const char* singular, const char* plural, int n);
+extern "C" char const* ngettext_wrapper(const char* singular, const char* plural, int n);
+extern "C" char const* pgettext_wrapper(const char* msgctxt, const char* msgid);
+extern "C" char const* npgettext_wrapper(const char* msgctxt, const char* singular, const char* plural, int n);
 
 void grab_textdomain(const std::string&, const char* ldir);
 void release_textdomain();
