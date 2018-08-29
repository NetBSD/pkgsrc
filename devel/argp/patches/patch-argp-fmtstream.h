$NetBSD: patch-argp-fmtstream.h,v 1.2 2018/08/29 18:08:08 kamil Exp $

--- argp-fmtstream.h.orig	2003-12-11 08:37:05.000000000 +0000
+++ argp-fmtstream.h
@@ -145,6 +145,7 @@ extern ssize_t argp_fmtstream_printf (ar
 				      __const char *__fmt, ...)
      PRINTF_STYLE(2,3);
 
+#if 0
 extern int __argp_fmtstream_putc (argp_fmtstream_t __fs, int __ch);
 extern int argp_fmtstream_putc (argp_fmtstream_t __fs, int __ch);
 
@@ -155,6 +156,7 @@ extern size_t __argp_fmtstream_write (ar
 				      __const char *__str, size_t __len);
 extern size_t argp_fmtstream_write (argp_fmtstream_t __fs,
 				    __const char *__str, size_t __len);
+#endif
 
 /* Access macros for various bits of state.  */
 #define argp_fmtstream_lmargin(__fs) ((__fs)->lmargin)
@@ -164,6 +166,7 @@ extern size_t argp_fmtstream_write (argp
 #define __argp_fmtstream_rmargin argp_fmtstream_rmargin
 #define __argp_fmtstream_wmargin argp_fmtstream_wmargin
 
+#if 0
 /* Set __FS's left margin to LMARGIN and return the old value.  */
 extern size_t argp_fmtstream_set_lmargin (argp_fmtstream_t __fs,
 					  size_t __lmargin);
@@ -185,6 +188,7 @@ extern size_t __argp_fmtstream_set_wmarg
 /* Return the column number of the current output point in __FS.  */
 extern size_t argp_fmtstream_point (argp_fmtstream_t __fs);
 extern size_t __argp_fmtstream_point (argp_fmtstream_t __fs);
+#endif
 
 /* Internal routines.  */
 extern void _argp_fmtstream_update (argp_fmtstream_t __fs);
@@ -208,7 +212,11 @@ extern int __argp_fmtstream_ensure (argp
 #endif
 
 #ifndef ARGP_FS_EI
+#if defined(__GNUC__) && !defined(__GNUC_STDC_INLINE__) && 0
 #define ARGP_FS_EI extern inline
+#else
+#define ARGP_FS_EI static inline
+#endif
 #endif
 
 ARGP_FS_EI size_t
