$NetBSD: patch-libinterp_corefcn_input.cc,v 1.2 2020/04/12 21:19:32 adam Exp $

Do not conflict between header and body

--- libinterp/corefcn/input.cc.orig	2020-01-28 01:57:35.000000000 +0000
+++ libinterp/corefcn/input.cc
@@ -521,7 +521,7 @@ namespace octave
               ? octave_locale_charset_wrapper () : m_mfile_encoding;
 
             // Check for valid encoding name.
-            void *codec
+            iconv_t codec
               = octave_iconv_open_wrapper (encoding.c_str (), "utf-8");
 
             if (codec == reinterpret_cast<void *> (-1))
