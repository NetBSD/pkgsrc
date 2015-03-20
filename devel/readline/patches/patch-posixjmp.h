$NetBSD: patch-posixjmp.h,v 1.1 2015/03/20 14:46:47 ryoon Exp $

* Fix link under Cygwin.
  From readline-3.8,8-1.src.patch from Cygwin.

--- posixjmp.h.orig	2012-12-24 03:20:50.000000000 +0000
+++ posixjmp.h
@@ -27,13 +27,13 @@
 
 #if defined (HAVE_POSIX_SIGSETJMP)
 #  define procenv_t	sigjmp_buf
-#  if !defined (__OPENNT)
+#  if !defined (__OPENNT) && !defined (__CYGWIN__)
 #    undef setjmp
 #    define setjmp(x)	sigsetjmp((x), 1)
 #    define setjmp_nosigs(x)	sigsetjmp((x), 0)
 #    undef longjmp
 #    define longjmp(x, n)	siglongjmp((x), (n))
-#  endif /* !__OPENNT */
+#  endif /* !__OPENNT && !__CYGWIN__ */
 #else
 #  define procenv_t	jmp_buf
 #  define setjmp_nosigs	setjmp
