$NetBSD: patch-Modules_readline.c,v 1.1 2024/10/09 19:53:20 adam Exp $

pkgsrc buildlink framework installs libedit headers to readline/ subdirectory.

VFunction type is not available on NetBSD`s native libedit.

--- Modules/readline.c.orig	2024-04-02 08:25:04.000000000 +0000
+++ Modules/readline.c
@@ -29,7 +29,7 @@
 #endif
 
 #ifdef WITH_EDITLINE
-#  include <editline/readline.h>
+#  include <readline/readline.h>
 #else
 /* GNU readline definitions */
 #  undef HAVE_CONFIG_H /* Else readline/chardefs.h includes strings.h */
@@ -443,7 +443,7 @@ readline_set_completion_display_matches_
 #if defined(HAVE_RL_COMPDISP_FUNC_T)
         (rl_compdisp_func_t *)on_completion_display_matches_hook : 0;
 #else
-        (VFunction *)on_completion_display_matches_hook : 0;
+        on_completion_display_matches_hook : 0;
 #endif
 #endif
     return result;
