$NetBSD: patch-argp-parse.c,v 1.2 2024/09/04 11:52:38 jperkin Exp $

Remove __THROW that might be defined to __attribute__((nothrow)) and would thus
cause the compilation to fail.
SunOS needs alloca.h.

--- argp-parse.c.orig	2003-12-11 08:37:05.000000000 +0000
+++ argp-parse.c
@@ -26,6 +26,10 @@
 #include <config.h>
 #endif
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 /* AIX requires this to be the first thing in the file.  */
 #ifndef __GNUC__
 # if HAVE_ALLOCA_H
@@ -1277,13 +1281,13 @@ weak_alias (__argp_input, _argp_input)
 /* Defined here, in case a user is not inlining the definitions in
  * argp.h */
 void
-__argp_usage (__const struct argp_state *__state) __THROW
+__argp_usage (__const struct argp_state *__state)
 {
   __argp_state_help (__state, stderr, ARGP_HELP_STD_USAGE);
 }
 
 int
-__option_is_short (__const struct argp_option *__opt) __THROW
+__option_is_short (__const struct argp_option *__opt)
 {
   if (__opt->flags & OPTION_DOC)
     return 0;
@@ -1297,7 +1301,7 @@ __option_is_short (__const struct argp_o
 }
 
 int
-__option_is_end (__const struct argp_option *__opt) __THROW
+__option_is_end (__const struct argp_option *__opt)
 {
   return !__opt->key && !__opt->name && !__opt->doc && !__opt->group;
 }
