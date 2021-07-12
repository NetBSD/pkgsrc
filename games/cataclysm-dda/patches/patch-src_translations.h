$NetBSD: patch-src_translations.h,v 1.2 2021/07/12 20:54:02 nia Exp $

Avoid overriding gettext functions with incompatible versions.

--- src/translations.h.orig	2021-07-03 05:00:06.000000000 +0000
+++ src/translations.h
@@ -144,25 +144,6 @@ static inline local_translation_cache<st
         return cache( arg ); \
     } )( msg ) )
 
-// ngettext overload taking an unsigned long long so that people don't need
-// to cast at call sites.  This is particularly relevant on 64-bit Windows where
-// size_t is bigger than unsigned long, so MSVC will try to encourage you to
-// add a cast.
-template<typename T, typename = std::enable_if_t<std::is_same<T, unsigned long long>::value>>
-ATTRIBUTE_FORMAT_ARG( 1 )
-inline const char *ngettext( const char *msgid, const char *msgid_plural, T n )
-{
-    // Leaving this long because it matches the underlying API.
-    // NOLINTNEXTLINE(cata-no-long)
-    return ngettext( msgid, msgid_plural, static_cast<unsigned long>( n ) );
-}
-
-const char *pgettext( const char *context, const char *msgid ) ATTRIBUTE_FORMAT_ARG( 2 );
-
-// same as pgettext, but supports plural forms like ngettext
-const char *npgettext( const char *context, const char *msgid, const char *msgid_plural,
-                       unsigned long long n ) ATTRIBUTE_FORMAT_ARG( 2 );
-
 #else // !LOCALIZE
 
 // on some systems <locale> pulls in libintl.h anyway,
