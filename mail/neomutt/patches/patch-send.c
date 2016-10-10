$NetBSD: patch-send.c,v 1.1 2016/10/10 19:26:31 wiz Exp $

forgotten-attachment: fix empty regex expression

The original regex was of the form "abc(|def)" to check for both "abc"
and "abcdef".  Unfortunately, the regex libraries on BSDs/MacOS don't
like this use of an empty sub-expression.

Expanding the regex to: "(abc|abcdef)" fixes the problem.

https://github.com/neomutt/neomutt/commit/3bc69ca25077b171f1ae9beee484629c5b5c6482

--- send.c.orig	2016-10-03 11:27:32.000000000 +0000
+++ send.c
@@ -1902,7 +1902,7 @@ main_loop:
     /* if the abort is automatic, print an error message */
     if (quadoption (OPT_ATTACH) == MUTT_YES)
     {
-      mutt_error _("Message contains text matching \"attach_keyword\". Not sending.");
+      mutt_error _("Message contains text matching \"$attach_keyword\". Not sending.");
     }
     goto main_loop;
   }
