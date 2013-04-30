$NetBSD: patch-include_vlc_fixups.h,v 1.3 2013/04/30 09:23:09 prlw1 Exp $

Build fix

--- include/vlc_fixups.h.orig	2011-07-12 18:11:23.000000000 +0000
+++ include/vlc_fixups.h
@@ -180,7 +180,10 @@ static inline char *getenv (const char *
 #ifndef HAVE_USELOCALE
 #define LC_NUMERIC_MASK  0
 #define LC_MESSAGES_MASK 0
+#include <stdlib.h>
+#ifndef __LOCALE_T_DECLARED
 typedef void *locale_t;
+#endif
 static inline locale_t uselocale(locale_t loc)
 {
     (void)loc;
