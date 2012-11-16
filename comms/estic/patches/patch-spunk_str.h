$NetBSD: patch-spunk_str.h,v 1.1 2012/11/16 00:37:47 joerg Exp $

--- spunk/str.h.orig	1996-12-18 13:18:50.000000000 +0000
+++ spunk/str.h
@@ -91,6 +91,13 @@ extern const class String EmptyString;
 // Note: This string class may not work with strings greater than INT_MAX or
 //       0xFFFF, whichever is less
 
+String ShowControls (const String& S, unsigned Style = ccDefault);
+String HideControls (const String& S);
+int Match (const char* Source, const char* Pattern);
+int Match (const String& Source, const String& Pattern);
+int Match (const String& Source, const char* Pattern);
+int Match (const char* Source, const String& Pattern);
+String FormatStr (const char* S, ...);
 
 class String : public Streamable {
 
@@ -303,7 +310,7 @@ public:
     // representation by the character itself, e.g. replace "\n" by the
     // character with code 13.
 
-    friend String ShowControls (const String& S, unsigned Style = ccDefault);
+    friend String ShowControls (const String& S, unsigned Style);
     // Recode the given string and replace every control character by it's
     // visible representation, e.g. "\n" instead of the character with code
     // code 13.
