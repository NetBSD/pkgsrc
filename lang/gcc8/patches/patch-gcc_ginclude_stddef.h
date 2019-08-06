$NetBSD: patch-gcc_ginclude_stddef.h,v 1.2 2019/08/06 06:16:16 maya Exp $

handle netbsd/arm not using the same include guards for
ansi.h as other archs

Upstreamed in 2018-06-20 (GCC 9.x)

--- gcc/ginclude/stddef.h.orig	2017-01-01 12:07:43.000000000 +0000
+++ gcc/ginclude/stddef.h
@@ -46,9 +46,7 @@ see the files COPYING3 and COPYING.RUNTI
 /* This avoids lossage on SunOS but only if stdtypes.h comes first.
    There's no way to win with the other order!  Sun lossage.  */
 
-/* On 4.3bsd-net2, make sure ansi.h is included, so we have
-   one less case to deal with in the following.  */
-#if defined (__BSD_NET2__) || defined (____386BSD____) || (defined (__FreeBSD__) && (__FreeBSD__ < 5)) || defined(__NetBSD__)
+#if defined(__NetBSD__)
 #include <machine/ansi.h>
 #endif
 /* On FreeBSD 5, machine/ansi.h does not exist anymore... */
@@ -56,11 +54,7 @@ see the files COPYING3 and COPYING.RUNTI
 #include <sys/_types.h>
 #endif
 
-/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
-   defined if the corresponding type is *not* defined.
-   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
-   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
-#if defined(_ANSI_H_) || defined(_MACHINE_ANSI_H_) || defined(_X86_64_ANSI_H_)  || defined(_I386_ANSI_H_)
+#if defined(__NetBSD__)
 #if !defined(_SIZE_T_) && !defined(_BSD_SIZE_T_)
 #define _SIZE_T
 #endif
@@ -87,7 +81,7 @@ see the files COPYING3 and COPYING.RUNTI
 #undef _WCHAR_T_
 #undef _BSD_WCHAR_T_
 #endif
-#endif /* defined(_ANSI_H_) || defined(_MACHINE_ANSI_H_) || defined(_X86_64_ANSI_H_) || defined(_I386_ANSI_H_) */
+#endif /* defined(__NetBSD__) */
 
 /* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
    Just ignore it.  */
@@ -359,11 +353,7 @@ typedef __WINT_TYPE__ wint_t;
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
@@ -391,7 +381,7 @@ typedef __WINT_TYPE__ wint_t;
 #undef _WCHAR_T_
 #undef _BSD_WCHAR_T_
 #endif
-#endif /* _ANSI_H_ || _MACHINE_ANSI_H_ || _X86_64_ANSI_H_ || _I386_ANSI_H_ */
+#endif /* __NetBSD__ */
 
 #endif /* __sys_stdtypes_h */
 
