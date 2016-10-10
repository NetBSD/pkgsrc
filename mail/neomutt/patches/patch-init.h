$NetBSD: patch-init.h,v 1.1 2016/10/10 19:26:31 wiz Exp $

forgotten-attachment: fix empty regex expression

The original regex was of the form "abc(|def)" to check for both "abc"
and "abcdef".  Unfortunately, the regex libraries on BSDs/MacOS don't
like this use of an empty sub-expression.

Expanding the regex to: "(abc|abcdef)" fixes the problem.

https://github.com/neomutt/neomutt/commit/3bc69ca25077b171f1ae9beee484629c5b5c6482

--- init.h.orig	2016-10-03 11:27:32.000000000 +0000
+++ init.h
@@ -267,7 +267,7 @@ struct option_t MuttVars[] = {
   ** .pp
   ** For an explanation of ``soft-fill'', see the $$index_format documentation.
   */
-  { "attach_keyword",  DT_RX,  R_NONE, UL &AttachKeyword, UL "\\<attach(|ed|ments?)\\>" },
+  { "attach_keyword",  DT_RX,  R_NONE, UL &AttachKeyword, UL "\\<(attach|attached|attachments?)\\>" },
   /*
   ** .pp
   ** If $abort_noattach is not set to no, then the body of the message
