$NetBSD: patch-kldap_ber.h,v 1.3 2014/11/14 22:23:40 joerg Exp $

--- kldap/ber.h.orig	2014-11-04 21:19:27.000000000 +0000
+++ kldap/ber.h
@@ -57,7 +57,8 @@ class KLDAP_EXPORT Ber
 
     /**
      * Appends the data with the specified format to the Ber object.
-     * This function works like printf, except that it's appending the
+     * This function works like 
+     printf, except that it's appending the
      * parameters, not replacing them. The allowed format characters and
      * the expected parameter types are:
      * <ul>
@@ -114,8 +115,8 @@ class KLDAP_EXPORT Ber
      *   </li>
      * </ul>
      */
-    int printf( const QString &format, ... );
-    int scanf( const QString &format, ... );
+    int printf( const char *format, ... );
+    int scanf( const char *format, ... );
     unsigned int peekTag( int &size );
     unsigned int skipTag( int &size );
 
