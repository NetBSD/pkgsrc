$NetBSD: patch-src_translations.cpp,v 1.2 2021/07/12 20:54:02 nia Exp $

Avoid overriding gettext functions with incompatible versions.

--- src/translations.cpp.orig	2021-07-03 05:00:06.000000000 +0000
+++ src/translations.cpp
@@ -75,45 +75,6 @@ static std::string getAppleSystemLanguag
 static std::string getAndroidSystemLanguage();
 #endif
 
-const char *pgettext( const char *context, const char *msgid )
-{
-    // need to construct the string manually,
-    // to correctly handle strings loaded from json.
-    // could probably do this more efficiently without using std::string.
-    std::string context_id( context );
-    context_id += '\004';
-    context_id += msgid;
-    // null domain, uses global translation domain
-    const char *msg_ctxt_id = context_id.c_str();
-#if defined(__ANDROID__)
-    const char *translation = gettext( msg_ctxt_id );
-#else
-    const char *translation = dcgettext( nullptr, msg_ctxt_id, LC_MESSAGES );
-#endif
-    if( translation == msg_ctxt_id ) {
-        return msgid;
-    } else {
-        return translation;
-    }
-}
-
-const char *npgettext( const char *const context, const char *const msgid,
-                       const char *const msgid_plural, const unsigned long long n )
-{
-    const std::string context_id = std::string( context ) + '\004' + msgid;
-    const char *const msg_ctxt_id = context_id.c_str();
-#if defined(__ANDROID__)
-    const char *const translation = ngettext( msg_ctxt_id, msgid_plural, n );
-#else
-    const char *const translation = dcngettext( nullptr, msg_ctxt_id, msgid_plural, n, LC_MESSAGES );
-#endif
-    if( translation == msg_ctxt_id ) {
-        return n == 1 ? msgid : msgid_plural;
-    } else {
-        return translation;
-    }
-}
-
 void select_language()
 {
     auto languages = get_options().get_option( "USE_LANG" ).getItems();
