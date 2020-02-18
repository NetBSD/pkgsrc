$NetBSD: patch-src_ber.h,v 1.1 2020/02/18 16:49:13 joerg Exp $

--- src/ber.h.orig	2020-01-14 16:17:30.291511893 +0000
+++ src/ber.h
@@ -115,8 +115,8 @@ public:
      *   </li>
      * </ul>
      */
-    int printf(QString format, ...); // Passing by-value since it's used by va_start
-    int scanf(QString format, ...);
+    int printf(const char *format, ...);
+    int scanf(const char *format, ...);
     unsigned int peekTag(int &size);
     unsigned int skipTag(int &size);
 
