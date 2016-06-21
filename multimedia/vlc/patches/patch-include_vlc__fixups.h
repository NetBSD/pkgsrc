$NetBSD: patch-include_vlc__fixups.h,v 1.3 2016/06/21 17:58:05 joerg Exp $

on NetBSD-current, just define "uselocale", nothing else
fixes build

static_assert: Assume that a compiler in C11 or C++11 frontend mode
has the _Static_assert keyword, but define the macro if it is missing
from the headers.

--- include/vlc_fixups.h.orig	2015-04-13 19:54:35.000000000 +0000
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
@@ -238,9 +250,12 @@ static inline locale_t newlocale(int mas
     return NULL;
 }
 #endif
+#endif
 
-#if !defined (HAVE_STATIC_ASSERT)
+#if !defined (static_assert)
+# if !(__STDC_VERSION__ - 0 >= 201112L || __cplusplus >= 201103L)
 # define _Static_assert(x, s) ((void) sizeof (struct { unsigned:-!(x); }))
+# endif
 # define static_assert _Static_assert
 #endif
 
