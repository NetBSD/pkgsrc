$NetBSD: patch-include_vlc__fixups.h,v 1.2 2015/10/25 11:00:18 wiz Exp $

on NetBSD-current, just define "uselocale", nothing else
fixes build

static_assert: a C compiler is used to detect if this symbol
exists in assert.h, but the header file is included by a c++
compiler too.

--- include/vlc_fixups.h.orig	2015-02-17 09:07:37.000000000 +0000
+++ include/vlc_fixups.h
@@ -218,16 +218,28 @@ int posix_memalign (void **, size_t, siz
 
 /* locale.h */
 #ifndef HAVE_USELOCALE
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if __NetBSD_Version__ >= 699002300
+/* NetBSD-current has locale_t but no uselocale */
+#define NetBSD_LOCALE_HACK
+#endif
+#endif
+#ifdef NetBSD_LOCALE_HACK
+#include <locale.h>
+#else
 #define LC_ALL_MASK      0
 #define LC_NUMERIC_MASK  0
 #define LC_MESSAGES_MASK 0
 #define LC_GLOBAL_LOCALE ((locale_t)(uintptr_t)1)
 typedef void *locale_t;
+#endif
 static inline locale_t uselocale(locale_t loc)
 {
     (void)loc;
     return NULL;
 }
+#ifndef NetBSD_LOCALE_HACK
 static inline void freelocale(locale_t loc)
 {
     (void)loc;
@@ -238,8 +250,9 @@ static inline locale_t newlocale(int mas
     return NULL;
 }
 #endif
+#endif
 
-#if !defined (HAVE_STATIC_ASSERT)
+#if !defined (static_assert)
 # define _Static_assert(x, s) ((void) sizeof (struct { unsigned:-!(x); }))
 # define static_assert _Static_assert
 #endif
