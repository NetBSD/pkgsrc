$NetBSD: patch-include_vlc_fixups.h,v 1.1 2013/04/29 22:53:57 prlw1 Exp $

build fix

--- include/vlc_fixups.h.orig	2011-07-12 18:11:23.000000000 +0000
+++ include/vlc_fixups.h
@@ -180,7 +180,12 @@ static inline char *getenv (const char *
 #ifndef HAVE_USELOCALE
 #define LC_NUMERIC_MASK  0
 #define LC_MESSAGES_MASK 0
+#ifdef HAVE_LOCALE_H
+#include <locale.h>
+#endif
+#ifndef HAVE_LOCALE_T
 typedef void *locale_t;
+#endif
 static inline locale_t uselocale(locale_t loc)
 {
     (void)loc;
