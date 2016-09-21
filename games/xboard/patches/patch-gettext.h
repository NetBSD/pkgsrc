$NetBSD: patch-gettext.h,v 1.1 2016/09/21 21:45:05 kamil Exp $

Address conflicts of local gettext.h with /usr/include/libintl.h on
NetBSD-7.99.36. Undefine system symbols and allow package's specific ones.

--- gettext.h.orig	2014-10-18 05:24:43.000000000 +0000
+++ gettext.h
@@ -186,8 +186,14 @@ npgettext_aux (const char *domain,
 #include <stdlib.h>
 #endif
 
+#ifdef pgettext_expr
+#undef pgettext_expr
+#endif
 #define pgettext_expr(Msgctxt, Msgid) \
   dcpgettext_expr (NULL, Msgctxt, Msgid, LC_MESSAGES)
+#ifdef dpgettext_expr
+#undef dpgettext_expr
+#endif
 #define dpgettext_expr(Domainname, Msgctxt, Msgid) \
   dcpgettext_expr (Domainname, Msgctxt, Msgid, LC_MESSAGES)
 
@@ -198,6 +204,11 @@ __inline
 inline
 #endif
 #endif
+
+#ifdef dcpgettext_expr
+#undef dcpgettext_expr
+#endif
+
 static const char *
 dcpgettext_expr (const char *domain,
                  const char *msgctxt, const char *msgid,
@@ -231,8 +242,17 @@ dcpgettext_expr (const char *domain,
   return msgid;
 }
 
+#ifdef npgettext_expr
+#undef npgettext_expr
+#endif
+
 #define npgettext_expr(Msgctxt, Msgid, MsgidPlural, N) \
   dcnpgettext_expr (NULL, Msgctxt, Msgid, MsgidPlural, N, LC_MESSAGES)
+
+#ifdef dnpgettext_expr
+#undef dnpgettext_expr
+#endif
+
 #define dnpgettext_expr(Domainname, Msgctxt, Msgid, MsgidPlural, N) \
   dcnpgettext_expr (Domainname, Msgctxt, Msgid, MsgidPlural, N, LC_MESSAGES)
 
@@ -243,6 +263,11 @@ __inline
 inline
 #endif
 #endif
+
+#ifdef dcnpgettext_expr
+#undef dcnpgettext_expr
+#endif
+
 static const char *
 dcnpgettext_expr (const char *domain,
                   const char *msgctxt, const char *msgid,
