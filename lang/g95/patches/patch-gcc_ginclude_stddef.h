$NetBSD: patch-gcc_ginclude_stddef.h,v 1.1 2013/05/20 05:47:34 adam Exp $

DragonFly BSD support (_PTRDIFF_T_DECLARED is also needed on dfly).

--- ../gcc-4.1.2/gcc/ginclude/stddef.h.orig	2005-06-25 01:11:52.000000000 +0000
+++ ../gcc-4.1.2/gcc/ginclude/stddef.h
@@ -62,6 +62,10 @@ Boston, MA 02110-1301, USA.  */
 #include <sys/_types.h>
 #endif
 
+#if defined(__DragonFly__)
+#include <sys/types.h>
+#endif
+
 /* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
    defined if the corresponding type is *not* defined.
    FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_ */
@@ -131,6 +135,7 @@ _TYPE_wchar_t;
    or if we want this type in particular.  */
 #if defined (_STDDEF_H) || defined (__need_ptrdiff_t)
 #ifndef _PTRDIFF_T	/* in case <sys/types.h> has defined it. */
+#ifndef _PTRDIFF_T_DECLARED
 #ifndef _T_PTRDIFF_
 #ifndef _T_PTRDIFF
 #ifndef __PTRDIFF_T
@@ -139,6 +144,7 @@ _TYPE_wchar_t;
 #ifndef ___int_ptrdiff_t_h
 #ifndef _GCC_PTRDIFF_T
 #define _PTRDIFF_T
+#define _PTRDIFF_T_DECLARED
 #define _T_PTRDIFF_
 #define _T_PTRDIFF
 #define __PTRDIFF_T
@@ -157,6 +163,7 @@ typedef __PTRDIFF_TYPE__ ptrdiff_t;
 #endif /* __PTRDIFF_T */
 #endif /* _T_PTRDIFF */
 #endif /* _T_PTRDIFF_ */
+#endif /* _PTRDIFF_T_DECLARED */
 #endif /* _PTRDIFF_T */
 
 /* If this symbol has done its job, get rid of it.  */
@@ -202,8 +209,8 @@ typedef __PTRDIFF_TYPE__ ptrdiff_t;
 #define ___int_size_t_h
 #define _GCC_SIZE_T
 #define _SIZET_
-#if defined (__FreeBSD__) && (__FreeBSD__ >= 5)
-/* __size_t is a typedef on FreeBSD 5!, must not trash it. */
+#if (defined (__FreeBSD__) && (__FreeBSD__ >= 5)) || defined(__DragonFly__)
+/* __size_t is a typedef on FreeBSD 5 and on DragonFly BSD!, must not trash it. */
 #else
 #define __size_t
 #endif
