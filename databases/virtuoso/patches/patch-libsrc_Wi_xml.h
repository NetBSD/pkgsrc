$NetBSD: patch-libsrc_Wi_xml.h,v 1.1 2013/04/13 13:16:02 jaapb Exp $

boolean type already defined
--- libsrc/Wi/xml.h.orig	2012-03-23 12:28:31.000000000 +0000
+++ libsrc/Wi/xml.h
@@ -83,16 +83,6 @@ encoding_handler_t *intl_find_user_chars
 
 #define XML_CHAR_ESCAPE(c,s) xml_escapes [c] = s;
 
-#ifndef __cplusplus
-/* Types definition */
-#ifndef _boolean
-typedef enum
-  {
-    false, true
-  }
-_boolean;
-#endif
-#endif
 
 
 
