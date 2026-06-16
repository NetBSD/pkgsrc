$NetBSD: patch-src_include_lib.h,v 1.1 2026/06/16 11:51:09 nia Exp $

Declare inline function static to avoid multiple definitions in
a static library:

src/include/lib.h:111: multiple definition of
 `is_invalid_input_char'; libgroff.a

This is safe because libgroff.a is private.

--- src/include/lib.h.orig	2026-06-16 10:45:35.068542661 +0000
+++ src/include/lib.h
@@ -106,7 +106,7 @@ int mksdir(char *tmpl);
 
   extern char invalid_char_table[];
 
-  inline bool is_invalid_input_char(int c)
+  static inline bool is_invalid_input_char(int c)
   {
     return (c >= 0 && invalid_char_table[c]);
   }
