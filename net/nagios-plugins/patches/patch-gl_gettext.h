$NetBSD: patch-gl_gettext.h,v 1.1 2017/09/09 22:47:35 joerg Exp $

Avoid redefining pgettext_expr and friends on systems that have them
already in libintl.h

--- gl/gettext.h.orig	2017-09-09 21:15:30.222205401 +0000
+++ gl/gettext.h
@@ -180,7 +180,7 @@ npgettext_aux (const char *domain,
 /* The same thing extended for non-constant arguments.  Here MSGCTXT and MSGID
    can be arbitrary expressions.  But for string literals these macros are
    less efficient than those above.  */
-
+#if !defined(pgettext_expr)
 #include <string.h>
 
 #if (((__GNUC__ >= 3 || __GNUG__ >= 2) && !defined __STRICT_ANSI__) \
@@ -284,5 +284,6 @@ dcnpgettext_expr (const char *domain,
     }
   return (n == 1 ? msgid : msgid_plural);
 }
+#endif
 
 #endif /* NAGIOS_GL_GETTEXT_H_INCLUDED */
