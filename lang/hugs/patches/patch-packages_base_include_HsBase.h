$NetBSD: patch-packages_base_include_HsBase.h,v 1.3 2015/12/29 23:34:48 dholland Exp $

Don't declare own execvpe() if the system already has it.
Patch up gcc inline mess.

--- packages/base/include/HsBase.h.orig	2006-09-20 22:01:52.000000000 +0000
+++ packages/base/include/HsBase.h
@@ -149,7 +149,7 @@ int inputReady(int fd, int msecs, int is
 /* in Signals.c */
 extern HsInt nocldstop;
 
-#if !defined(_MSC_VER) && !defined(__MINGW32__) && !defined(_WIN32)
+#if !defined(_MSC_VER) && !defined(__MINGW32__) && !defined(_WIN32) && !HAVE_EXECVPE
 /* in execvpe.c */
 extern int execvpe(char *name, char *const argv[], char **envp);
 extern void pPrPr_disableITimers (void);
@@ -221,7 +221,11 @@ StgWord64 stg_integerToWord64 (StgInt sa
 # if defined(_MSC_VER)
 #  define INLINE extern __inline
 # elif defined(__GNUC__)
-#  define INLINE extern inline
+#  ifdef __GNUC_STDC_INLINE__
+#   define INLINE extern inline __attribute__((__gnu_inline__))
+#  else
+#   define INLINE extern inline
+#  endif
 # else
 #  define INLINE inline
 # endif
