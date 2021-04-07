$NetBSD: patch-src_ber.h,v 1.2 2021/04/07 12:28:15 markd Exp $

--- src/core/ber.h.orig	2020-01-14 16:17:30.291511893 +0000
+++ src/core/ber.h
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
 
