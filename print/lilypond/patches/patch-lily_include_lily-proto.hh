$NetBSD: patch-lily_include_lily-proto.hh,v 1.1 2013/04/01 12:20:47 joerg Exp $

Issue 2208.

--- lily/include/lily-proto.hh.orig	2013-03-31 14:59:54.000000000 +0000
+++ lily/include/lily-proto.hh
@@ -198,9 +198,6 @@ class Translator_change;
 class Translator_group;
 class Transposed_music;
 class yyFlexLexer;
-
-typedef void (*Engraver_void_function_engraver_grob_info) (Engraver *,
-                                                           Grob_info);
-typedef void (*Translator_void_method_ptr) (Translator *);
-
+typedef void (Engraver::*Engraver_void_function_engraver_grob_info) (Grob_info);
+typedef void (Translator::*Translator_void_method_ptr) ();
 #endif /* LILY_PROTO_HH */
