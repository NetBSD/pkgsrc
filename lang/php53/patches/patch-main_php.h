$NetBSD: patch-main_php.h,v 1.1 2014/11/21 14:13:51 joerg Exp $

--- main/php.h.orig	2014-11-20 21:45:33.000000000 +0000
+++ main/php.h
@@ -419,26 +419,8 @@ END_EXTERN_C()
  */
 
 #ifndef XtOffset
-#if defined(CRAY) || (defined(__arm) && !(defined(LINUX) || defined(__riscos__)))
-#ifdef __STDC__
-#define XtOffset(p_type, field) _Offsetof(p_type, field)
-#else
-#ifdef CRAY2
-#define XtOffset(p_type, field) \
-    (sizeof(int)*((unsigned int)&(((p_type)NULL)->field)))
-
-#else /* !CRAY2 */
-
-#define XtOffset(p_type, field) ((unsigned int)&(((p_type)NULL)->field))
-
-#endif /* !CRAY2 */
-#endif /* __STDC__ */
-#else /* ! (CRAY || __arm) */
-
 #define XtOffset(p_type, field) \
     ((long) (((char *) (&(((p_type)NULL)->field))) - ((char *) NULL)))
-
-#endif /* !CRAY */
 #endif /* ! XtOffset */
 
 #ifndef XtOffsetOf
