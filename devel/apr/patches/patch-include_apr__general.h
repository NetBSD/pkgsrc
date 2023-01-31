$NetBSD: patch-include_apr__general.h,v 1.2 2023/01/31 18:41:49 wiz Exp $

Unconditionally use the !ARM, !CRAY version of APR_OFFSET.

--- include/apr_general.h.orig	2014-11-21 11:49:41.000000000 +0000
+++ include/apr_general.h
@@ -67,36 +67,9 @@ extern "C" {
 /** signal numbers typedef */
 typedef int               apr_signum_t;
 
-/**
- * Finding offsets of elements within structures.
- * Taken from the X code... they've sweated portability of this stuff
- * so we don't have to.  Sigh...
- * @param p_type pointer type name
- * @param field  data field within the structure pointed to
- * @return offset
- */
-
-#if defined(CRAY) || (defined(__arm) && !(defined(LINUX) || defined(__FreeBSD__)))
-#ifdef __STDC__
-#define APR_OFFSET(p_type,field) _Offsetof(p_type,field)
-#else
-#ifdef CRAY2
-#define APR_OFFSET(p_type,field) \
-        (sizeof(int)*((unsigned int)&(((p_type)NULL)->field)))
-
-#else /* !CRAY2 */
-
-#define APR_OFFSET(p_type,field) ((unsigned int)&(((p_type)NULL)->field))
-
-#endif /* !CRAY2 */
-#endif /* __STDC__ */
-#else /* ! (CRAY || __arm) */
-
 #define APR_OFFSET(p_type,field) \
         ((long) (((char *) (&(((p_type)NULL)->field))) - ((char *) NULL)))
 
-#endif /* !CRAY */
-
 /**
  * Finding offsets of elements within structures.
  * @param s_type structure type name
