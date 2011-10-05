$NetBSD: patch-src_m__binbuf.c,v 1.2 2011/10/05 20:02:48 wiz Exp $

alloca.h is not portable.
https://sourceforge.net/tracker/?func=detail&aid=3411730&group_id=55736&atid=478072

--- src/m_binbuf.c.orig	2011-03-10 06:02:41.000000000 +0000
+++ src/m_binbuf.c
@@ -530,10 +530,10 @@ done:
 
 #define SMALLMSG 5
 #define HUGEMSG 1000
-#ifdef MSW
-#include <malloc.h>
-#else
+#if defined(HAVE_ALLOCA_H)
 #include <alloca.h>
+#elsif defined(HAVE_MALLOC_H)
+#include <malloc.h>
 #endif
 #if HAVE_ALLOCA
 #define ATOMS_ALLOCA(x, n) ((x) = (t_atom *)((n) < HUGEMSG ?  \
