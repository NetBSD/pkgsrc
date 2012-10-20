$NetBSD: patch-argp_argp-fmtstream.h,v 1.1 2012/10/20 22:13:28 joerg Exp $

--- argp/argp-fmtstream.h.orig	2004-11-19 22:51:26.000000000 +0000
+++ argp/argp-fmtstream.h
@@ -139,6 +139,7 @@ extern ssize_t argp_fmtstream_printf (ar
    ;
 #endif
 
+#if 0
 extern int __argp_fmtstream_putc (argp_fmtstream_t __fs, int __ch);
 extern int argp_fmtstream_putc (argp_fmtstream_t __fs, int __ch);
 
@@ -149,6 +150,7 @@ extern size_t __argp_fmtstream_write (ar
 				      __const char *__str, size_t __len);
 extern size_t argp_fmtstream_write (argp_fmtstream_t __fs,
 				    __const char *__str, size_t __len);
+#endif
 
 /* Access macros for various bits of state.  */
 #define argp_fmtstream_lmargin(__fs) ((__fs)->lmargin)
@@ -158,6 +160,7 @@ extern size_t argp_fmtstream_write (argp
 #define __argp_fmtstream_rmargin argp_fmtstream_rmargin
 #define __argp_fmtstream_wmargin argp_fmtstream_wmargin
 
+#if 0
 /* Set __FS's left margin to LMARGIN and return the old value.  */
 extern size_t argp_fmtstream_set_lmargin (argp_fmtstream_t __fs,
 					  size_t __lmargin);
@@ -179,6 +182,7 @@ extern size_t __argp_fmtstream_set_wmarg
 /* Return the column number of the current output point in __FS.  */
 extern size_t argp_fmtstream_point (argp_fmtstream_t __fs);
 extern size_t __argp_fmtstream_point (argp_fmtstream_t __fs);
+#endif
 
 /* Internal routines.  */
 extern void _argp_fmtstream_update (argp_fmtstream_t __fs);
@@ -202,7 +206,11 @@ extern int __argp_fmtstream_ensure (argp
 #endif
 
 #ifndef ARGP_FS_EI
+#if defined(__GNUC__) && !defined(__GNUC_STDC_INLINE__)
 #define ARGP_FS_EI extern inline
+#else
+#define ARGP_FS_EI inline
+#endif
 #endif
 
 ARGP_FS_EI size_t
