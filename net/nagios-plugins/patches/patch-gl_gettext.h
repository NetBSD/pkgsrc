$NetBSD: patch-gl_gettext.h,v 1.2 2023/01/09 00:28:41 sekiya Exp $

Avoid redefining pgettext_expr and friends on systems that have them
already in libintl.h

--- gl/gettext.h.orig	2019-12-05 06:53:08.000000000 +0900
+++ gl/gettext.h	2023-01-09 08:51:04.874713509 +0900
@@ -180,7 +180,7 @@
 /* The same thing extended for non-constant arguments.  Here MSGCTXT and MSGID
    can be arbitrary expressions.  But for string literals these macros are
    less efficient than those above.  */
-
+#if !defined(pgettext_expr)
 #include <string.h>
 
 #if (((__GNUC__ >= 3 || __GNUG__ >= 2) && !defined __STRICT_ANSI__) \
@@ -284,5 +284,6 @@
     }
   return (n == 1 ? msgid : msgid_plural);
 }
+#endif
 
 #endif /* _LIBGETTEXT_H */
