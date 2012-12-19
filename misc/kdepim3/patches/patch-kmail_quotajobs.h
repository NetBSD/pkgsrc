$NetBSD: patch-kmail_quotajobs.h,v 1.1 2012/12/19 17:21:49 jperkin Exp $

Avoid "error: call of overloaded 'pow(int, int&)' is ambiguous".

--- kmail/quotajobs.h.orig	2012-12-19 16:02:07.606082279 +0000
+++ kmail/quotajobs.h	2012-12-19 16:02:38.857687045 +0000
@@ -72,7 +72,7 @@
   QString toString() const {
     if ( isValid() && !isEmpty() ) {
       readConfig();
-      int factor = static_cast<int> ( pow( 1000, mFactor ) );
+      int factor = static_cast<int> ( pow( (double)1000, mFactor ) );
       return i18n("%1 of %2 %3 used").arg( mCurrent.toInt() / factor )
                                 .arg( mMax.toInt() / factor ).arg( mUnits );
     }
