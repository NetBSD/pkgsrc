$NetBSD: patch-src_ap.h,v 1.1 2012/02/16 11:37:27 hans Exp $

--- src/ap.h.orig	2006-07-07 08:54:24.000000000 +0200
+++ src/ap.h	2009-12-26 00:34:39.235405370 +0100
@@ -39,6 +39,8 @@ const bool ONE_OF = false;
 
 class CS_FILE {};
 
+#undef CS
+
 class CS {
 private:
   char* _name;
