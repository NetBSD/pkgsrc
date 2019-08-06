$NetBSD: patch-gcc_ginclude_stddef.h,v 1.3 2019/08/06 06:16:14 maya Exp $

Avoid relying on fragile include guards for NetBSD ansi.h.
DragonflyBSD support

Both upstreamed (GCC 9.x, GCC 5.x respectively)

--- gcc/ginclude/stddef.h.orig	2019-08-06 05:58:50.166834311 +0000
+++ gcc/ginclude/stddef.h
@@ -46,21 +46,24 @@ see the files COPYING3 and COPYING.RUNTI
 /* This avoids lossage on SunOS but only if stdtypes.h comes first.
    There's no way to win with the other order!  Sun lossage.  */
 
-/* On 4.3bsd-net2, make sure ansi.h is included, so we have
-   one less case to deal with in the following.  */
-#if defined (__BSD_NET2__) || defined (____386BSD____) || (defined (__FreeBSD__) && (__FreeBSD__ < 5)) || defined(__NetBSD__)
+#if defined(__NetBSD__)
 #include <machine/ansi.h>
+#if !defined(_MACHINE_ANSI_H_)
+#if defined(_I386_ANSI_H_) || defined(_X86_64_ANSI_H_)
+#define _MACHINE_ANSI_H_
+#endif
+#endif
 #endif
 /* On FreeBSD 5, machine/ansi.h does not exist anymore... */
 #if defined (__FreeBSD__) && (__FreeBSD__ >= 5)
 #include <sys/_types.h>
 #endif
 
-/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
-   defined if the corresponding type is *not* defined.
-   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
-   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
-#if defined(_ANSI_H_) || defined(_MACHINE_ANSI_H_) || defined(_X86_64_ANSI_H_)  || defined(_I386_ANSI_H_)
+#if defined(__DragonFly__)
+#include <sys/types.h>
+#endif
+
+#if defined(__NetBSD__)
 #if !defined(_SIZE_T_) && !defined(_BSD_SIZE_T_)
 #define _SIZE_T
 #endif
@@ -87,7 +90,7 @@ see the files COPYING3 and COPYING.RUNTI
 #undef _WCHAR_T_
 #undef _BSD_WCHAR_T_
 #endif
-#endif /* defined(_ANSI_H_) || defined(_MACHINE_ANSI_H_) || defined(_X86_64_ANSI_H_) || defined(_I386_ANSI_H_) */
+#endif /* defined(__NetBSD__) */
 
 /* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
    Just ignore it.  */
@@ -133,6 +136,7 @@ _TYPE_wchar_t;
 #ifndef _BSD_PTRDIFF_T_
 #ifndef ___int_ptrdiff_t_h
 #ifndef _GCC_PTRDIFF_T
+#ifndef _PTRDIFF_T_DECLARED /* DragonFly */
 #define _PTRDIFF_T
 #define _T_PTRDIFF_
 #define _T_PTRDIFF
@@ -141,10 +145,12 @@ _TYPE_wchar_t;
 #define _BSD_PTRDIFF_T_
 #define ___int_ptrdiff_t_h
 #define _GCC_PTRDIFF_T
+#define _PTRDIFF_T_DECLARED
 #ifndef __PTRDIFF_TYPE__
 #define __PTRDIFF_TYPE__ long int
 #endif
 typedef __PTRDIFF_TYPE__ ptrdiff_t;
+#endif /* _PTRDIFF_T_DECLARED */
 #endif /* _GCC_PTRDIFF_T */
 #endif /* ___int_ptrdiff_t_h */
 #endif /* _BSD_PTRDIFF_T_ */
@@ -198,6 +204,7 @@ typedef __PTRDIFF_TYPE__ ptrdiff_t;
 #define _GCC_SIZE_T
 #define _SIZET_
 #if (defined (__FreeBSD__) && (__FreeBSD__ >= 5)) \
+  || defined(__DragonFly__) \
   || defined(__FreeBSD_kernel__)
 /* __size_t is a typedef on FreeBSD 5, must not trash it. */
 #elif defined (__VMS__)
@@ -306,7 +313,7 @@ typedef _BSD_RUNE_T_ rune_t;
 /* FreeBSD 5 can't be handled well using "traditional" logic above
    since it no longer defines _BSD_RUNE_T_ yet still desires to export
    rune_t in some cases... */
-#if defined (__FreeBSD__) && (__FreeBSD__ >= 5)
+#if defined (__DragonFly__) || (defined (__FreeBSD__) && (__FreeBSD__ >= 5))
 #if !defined (_ANSI_SOURCE) && !defined (_POSIX_SOURCE)
 #if __BSD_VISIBLE
 #ifndef _RUNE_T_DECLARED
@@ -355,11 +362,7 @@ typedef __WINT_TYPE__ wint_t;
 #undef __need_wint_t
 #endif
 
-/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
-    are already defined.  */
-/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
-/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
-#if defined(_ANSI_H_) || defined(_MACHINE_ANSI_H_) || defined(_X86_64_ANSI_H_) || defined(_I386_ANSI_H_)
+#if defined(__NetBSD__)
 /*  The references to _GCC_PTRDIFF_T_, _GCC_SIZE_T_, and _GCC_WCHAR_T_
     are probably typos and should be removed before 2.8 is released.  */
 #ifdef _GCC_PTRDIFF_T_
@@ -387,7 +390,7 @@ typedef __WINT_TYPE__ wint_t;
 #undef _WCHAR_T_
 #undef _BSD_WCHAR_T_
 #endif
-#endif /* _ANSI_H_ || _MACHINE_ANSI_H_ || _X86_64_ANSI_H_ || _I386_ANSI_H_ */
+#endif /* __NetBSD__ */
 
 #endif /* __sys_stdtypes_h */
 
