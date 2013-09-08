$NetBSD: patch-src_misc_messages.c,v 1.1 2013/09/08 16:28:27 joerg Exp $

--- src/misc/messages.c.orig	2010-08-08 17:32:50.000000000 +0000
+++ src/misc/messages.c
@@ -301,7 +301,9 @@ void msg_GenericVa (vlc_object_t *p_this
         return;
 
     msg_bank_t *bank = libvlc_bank (p_this->p_libvlc);
+#ifndef LC_C_LOCALE
     locale_t locale = uselocale (bank->locale);
+#endif
 
 #ifndef __GLIBC__
     /* Expand %m to strerror(errno) - only once */
@@ -321,7 +323,9 @@ void msg_GenericVa (vlc_object_t *p_this
             char errbuf[2001];
             size_t errlen;
 
-#ifndef WIN32
+#ifdef LC_C_LOCALE
+            strncpy(errbuf, strerror_l( errno, bank->locale), 1001);
+#elif !defined(WIN32)
             strerror_r( errno, errbuf, 1001 );
 #else
             int sockerr = WSAGetLastError( );
@@ -361,7 +365,7 @@ void msg_GenericVa (vlc_object_t *p_this
 
     /* Convert message to string  */
     vlc_va_copy( args, _args );
-    if( vasprintf( &psz_str, psz_format, args ) == -1 )
+    if( vasprintf_l( &psz_str, bank->locale, psz_format, args ) == -1 )
         psz_str = NULL;
     va_end( args );
 
@@ -372,7 +376,9 @@ void msg_GenericVa (vlc_object_t *p_this
         fprintf( stderr, "main warning: can't store message (%m): " );
 #else
         char psz_err[1001];
-#ifndef WIN32
+#ifdef LC_C_LOCALE
+        strncpy(psz_err, strerror_l( errno, bank->locale), 1001 );
+#elif !defined(WIN32)
         /* we're not using GLIBC, so we are sure that the error description
          * will be stored in the buffer we provide to strerror_r() */
         strerror_r( errno, psz_err, 1001 );
@@ -384,14 +390,18 @@ void msg_GenericVa (vlc_object_t *p_this
 #endif
         vlc_va_copy( args, _args );
         /* We should use utf8_vfprintf - but it calls malloc()... */
-        vfprintf( stderr, psz_format, args );
+        vfprintf_l( stderr, bank->locale, psz_format, args );
         va_end( args );
         fputs( "\n", stderr );
         vlc_restorecancel (canc);
+#ifndef LC_C_LOCALE
         uselocale (locale);
+#endif
         return;
     }
+#ifndef LC_C_LOCALE
     uselocale (locale);
+#endif
 
     msg_item_t * p_item = malloc (sizeof (*p_item));
     if (p_item == NULL)
