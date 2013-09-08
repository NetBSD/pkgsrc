$NetBSD: patch-include_vlc__fixups.h,v 1.1 2013/09/08 16:28:27 joerg Exp $

--- include/vlc_fixups.h.orig	2013-05-15 20:39:43.000000000 +0000
+++ include/vlc_fixups.h
@@ -177,25 +177,7 @@ static inline char *getenv (const char *
 #   define ATTR_ALIGN(align)
 #endif
 
-#ifndef HAVE_USELOCALE
-#define LC_NUMERIC_MASK  0
-#define LC_MESSAGES_MASK 0
-typedef void *locale_t;
-static inline locale_t uselocale(locale_t loc)
-{
-    (void)loc;
-    return NULL;
-}
-static inline void freelocale(locale_t loc)
-{
-    (void)loc;
-}
-static inline locale_t newlocale(int mask, const char * locale, locale_t base)
-{
-    (void)mask; (void)locale; (void)base;
-    return NULL;
-}
-#endif
+#include <locale.h>
 
 #ifdef WIN32
 # include <dirent.h>
