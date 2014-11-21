$NetBSD: patch-Zend_zend__ini.h,v 1.1 2014/11/21 14:13:51 joerg Exp $

--- Zend/zend_ini.h.orig	2014-11-20 21:46:26.000000000 +0000
+++ Zend/zend_ini.h
@@ -28,27 +28,8 @@
 #define ZEND_INI_ALL (ZEND_INI_USER|ZEND_INI_PERDIR|ZEND_INI_SYSTEM)
 
 #ifndef XtOffsetOf
-# if defined(CRAY) || (defined(__arm) && !defined(LINUX))
-# ifdef __STDC__
-# define XtOffset(p_type, field) _Offsetof(p_type, field)
-# else
-# ifdef CRAY2
-# define XtOffset(p_type, field) \
-    (sizeof(int)*((unsigned int)&(((p_type)NULL)->field)))
-
-# else /* !CRAY2 */
-
-# define XtOffset(p_type, field) ((unsigned int)&(((p_type)NULL)->field))
-
-# endif /* !CRAY2 */
-# endif /* __STDC__ */
-# else /* ! (CRAY || __arm) */
-
 # define XtOffset(p_type, field) \
     ((long) (((char *) (&(((p_type)NULL)->field))) - ((char *) NULL)))
-
-# endif /* !CRAY */
-
 # ifdef offsetof
 # define XtOffsetOf(s_type, field) offsetof(s_type, field)
 # else
