$NetBSD: patch-libinterp_corefcn_input.cc,v 1.1 2019/03/05 11:11:12 ryoon Exp $

* Do not conflict between header and body

--- libinterp/corefcn/input.cc.orig	2019-02-23 17:33:37.000000000 +0000
+++ libinterp/corefcn/input.cc
@@ -521,7 +521,7 @@ namespace octave
               ? octave_locale_charset_wrapper () : m_mfile_encoding;
 
             // Check for valid codepage.
-            void *codec
+            iconv_t codec
               = octave_iconv_open_wrapper (codepage.c_str (), "utf-8");
 
             if (errno == EINVAL)
