$NetBSD: patch-.._gcc-4.0.3_gcc_ginclude_stddef.h,v 1.1 2011/02/19 16:06:31 rumko Exp $

DragonFly BSD support (_PTRDIFF_T_DECLARED is also needed on dfly).

--- ../gcc-4.0.3/gcc/ginclude/stddef.h.orig	2011-02-06 21:30:12 +0100
+++ ../gcc-4.0.3/gcc/ginclude/stddef.h	2011-02-06 21:31:14 +0100
@@ -62,6 +62,10 @@
 #include <sys/_types.h>
 #endif
 
+#if defined(__DragonFly__)
+#include <sys/types.h>
+#endif
+
 /* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
    defined if the corresponding type is *not* defined.
    FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_ */
@@ -131,6 +135,7 @@
    or if we want this type in particular.  */
 #if defined (_STDDEF_H) || defined (__need_ptrdiff_t)
 #ifndef _PTRDIFF_T	/* in case <sys/types.h> has defined it. */
+#ifndef _PTRDIFF_T_DECLARED
 #ifndef _T_PTRDIFF_
 #ifndef _T_PTRDIFF
 #ifndef __PTRDIFF_T
@@ -139,6 +144,7 @@
 #ifndef ___int_ptrdiff_t_h
 #ifndef _GCC_PTRDIFF_T
 #define _PTRDIFF_T
+#define _PTRDIFF_T_DECLARED
 #define _T_PTRDIFF_
 #define _T_PTRDIFF
 #define __PTRDIFF_T
@@ -157,6 +163,7 @@
 #endif /* __PTRDIFF_T */
 #endif /* _T_PTRDIFF */
 #endif /* _T_PTRDIFF_ */
+#endif /* _PTRDIFF_T_DECLARED */
 #endif /* _PTRDIFF_T */
 
 /* If this symbol has done its job, get rid of it.  */
@@ -202,8 +209,8 @@
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
