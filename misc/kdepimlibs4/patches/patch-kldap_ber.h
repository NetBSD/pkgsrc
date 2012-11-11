$NetBSD: patch-kldap_ber.h,v 1.1 2012/11/11 22:49:20 joerg Exp $

--- kldap/ber.h.orig	2012-11-08 10:20:45.000000000 +0000
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
 
