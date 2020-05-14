$NetBSD: patch-gcc_system.h,v 1.2 2020/05/14 19:18:54 joerg Exp $

--- gcc/system.h.orig	2014-01-02 22:23:26.000000000 +0000
+++ gcc/system.h
@@ -72,18 +72,22 @@ along with GCC; see the file COPYING3.  
 
 #if defined HAVE_DECL_PUTC_UNLOCKED && HAVE_DECL_PUTC_UNLOCKED
 
+# if !defined(__NetBSD__)
 # ifdef HAVE_PUTC_UNLOCKED
 #  undef putc
 #  define putc(C, Stream) putc_unlocked (C, Stream)
 # endif
+# endif
 # ifdef HAVE_PUTCHAR_UNLOCKED
 #  undef putchar
 #  define putchar(C) putchar_unlocked (C)
 # endif
+# if !defined(__NetBSD__)
 # ifdef HAVE_GETC_UNLOCKED
 #  undef getc
 #  define getc(Stream) getc_unlocked (Stream)
 # endif
+# endif
 # ifdef HAVE_GETCHAR_UNLOCKED
 #  undef getchar
 #  define getchar() getchar_unlocked ()
@@ -467,6 +471,8 @@ extern char *stpcpy (char *, const char 
 #endif
 
 #ifdef __cplusplus
+// Avoid messing with abort() use in libc++
+#include <exception>
 extern "C" {
 #endif
 
