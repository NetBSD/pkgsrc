$NetBSD: patch-argp.h,v 1.1 2023/03/12 12:38:56 js Exp $

Remove __THROW that might be defined to __attribute__((nothrow)) and would thus
cause the compilation to fail.

Remove everything in #ifdef __USE_EXTERN_INLINES, as this results in duplicate
definitions.

--- argp.h.orig	2003-12-11 08:37:05.000000000 +0000
+++ argp.h
@@ -27,10 +27,6 @@
 #define __need_error_t
 #include <errno.h>
 
-#ifndef __THROW
-# define __THROW
-#endif
-
 #ifndef __const
 # define __const const
 #endif
@@ -400,11 +396,11 @@ struct argp_state
 extern error_t argp_parse (__const struct argp *__restrict __argp,
 			   int __argc, char **__restrict __argv,
 			   unsigned __flags, int *__restrict __arg_index,
-			   void *__restrict __input) __THROW;
+			   void *__restrict __input);
 extern error_t __argp_parse (__const struct argp *__restrict __argp,
 			     int __argc, char **__restrict __argv,
 			     unsigned __flags, int *__restrict __arg_index,
-			     void *__restrict __input) __THROW;
+			     void *__restrict __input);
 
 /* Global variables.  */
 
@@ -468,10 +464,10 @@ extern error_t argp_err_exit_status;
    ARGP_HELP_*.  */
 extern void argp_help (__const struct argp *__restrict __argp,
 		       FILE *__restrict __stream,
-		       unsigned __flags, char *__restrict __name) __THROW;
+		       unsigned __flags, char *__restrict __name);
 extern void __argp_help (__const struct argp *__restrict __argp,
 			 FILE *__restrict __stream, unsigned __flags,
-			 char *__name) __THROW;
+			 char *__name);
 
 /* The following routines are intended to be called from within an argp
    parsing routine (thus taking an argp_state structure as the first
@@ -485,23 +481,23 @@ extern void __argp_help (__const struct
    from the set ARGP_HELP_*.  */
 extern void argp_state_help (__const struct argp_state *__restrict __state,
 			     FILE *__restrict __stream,
-			     unsigned int __flags) __THROW;
+			     unsigned int __flags);
 extern void __argp_state_help (__const struct argp_state *__restrict __state,
 			       FILE *__restrict __stream,
-			       unsigned int __flags) __THROW;
+			       unsigned int __flags);
 
 /* Possibly output the standard usage message for ARGP to stderr and exit.  */
-extern void argp_usage (__const struct argp_state *__state) __THROW;
-extern void __argp_usage (__const struct argp_state *__state) __THROW;
+extern void argp_usage (__const struct argp_state *__state);
+extern void __argp_usage (__const struct argp_state *__state);
 
 /* If appropriate, print the printf string FMT and following args, preceded
    by the program name and `:', to stderr, and followed by a `Try ... --help'
    message, then exit (1).  */
 extern void argp_error (__const struct argp_state *__restrict __state,
-			__const char *__restrict __fmt, ...) __THROW
+			__const char *__restrict __fmt, ...)
      PRINTF_STYLE(2,3);
 extern void __argp_error (__const struct argp_state *__restrict __state,
-			  __const char *__restrict __fmt, ...) __THROW
+			  __const char *__restrict __fmt, ...)
      PRINTF_STYLE(2,3);
 
 /* Similar to the standard gnu error-reporting function error(), but will
@@ -514,86 +510,38 @@ extern void __argp_error (__const struct
    parsing but don't reflect a (syntactic) problem with the input.  */
 extern void argp_failure (__const struct argp_state *__restrict __state,
 			  int __status, int __errnum,
-			  __const char *__restrict __fmt, ...) __THROW
+			  __const char *__restrict __fmt, ...)
      PRINTF_STYLE(4,5);
 extern void __argp_failure (__const struct argp_state *__restrict __state,
 			    int __status, int __errnum,
-			    __const char *__restrict __fmt, ...) __THROW
+			    __const char *__restrict __fmt, ...)
      PRINTF_STYLE(4,5);
 
 /* Returns true if the option OPT is a valid short option.  */
-extern int _option_is_short (__const struct argp_option *__opt) __THROW;
-extern int __option_is_short (__const struct argp_option *__opt) __THROW;
+extern int _option_is_short (__const struct argp_option *__opt);
+extern int __option_is_short (__const struct argp_option *__opt);
 
 /* Returns true if the option OPT is in fact the last (unused) entry in an
    options array.  */
-extern int _option_is_end (__const struct argp_option *__opt) __THROW;
-extern int __option_is_end (__const struct argp_option *__opt) __THROW;
+extern int _option_is_end (__const struct argp_option *__opt);
+extern int __option_is_end (__const struct argp_option *__opt);
 
 /* Return the input field for ARGP in the parser corresponding to STATE; used
    by the help routines.  */
 extern void *_argp_input (__const struct argp *__restrict __argp,
-			  __const struct argp_state *__restrict __state)
-     __THROW;
+			  __const struct argp_state *__restrict __state);
 extern void *__argp_input (__const struct argp *__restrict __argp,
-			   __const struct argp_state *__restrict __state)
-     __THROW;
+			   __const struct argp_state *__restrict __state);
 
 /* Used for extracting the program name from argv[0] */
-extern char *_argp_basename(char *name) __THROW;
-extern char *__argp_basename(char *name) __THROW;
+extern char *_argp_basename(char *name);
+extern char *__argp_basename(char *name);
 
 /* Getting the program name given an argp state */
 extern char *
-_argp_short_program_name(const struct argp_state *state) __THROW;
+_argp_short_program_name(const struct argp_state *state);
 extern char *
-__argp_short_program_name(const struct argp_state *state) __THROW;
-
-
-#ifdef __USE_EXTERN_INLINES
-
-# if !_LIBC
-#  define __argp_usage argp_usage
-#  define __argp_state_help argp_state_help
-#  define __option_is_short _option_is_short
-#  define __option_is_end _option_is_end
-# endif
-
-# ifndef ARGP_EI
-#  define ARGP_EI extern __inline__
-# endif
-
-ARGP_EI void
-__argp_usage (__const struct argp_state *__state) __THROW
-{
-  __argp_state_help (__state, stderr, ARGP_HELP_STD_USAGE);
-}
-
-ARGP_EI int
-__option_is_short (__const struct argp_option *__opt) __THROW
-{
-  if (__opt->flags & OPTION_DOC)
-    return 0;
-  else
-    {
-      int __key = __opt->key;
-      return __key > 0 && isprint (__key);
-    }
-}
-
-ARGP_EI int
-__option_is_end (__const struct argp_option *__opt) __THROW
-{
-  return !__opt->key && !__opt->name && !__opt->doc && !__opt->group;
-}
-
-# if !_LIBC
-#  undef __argp_usage
-#  undef __argp_state_help
-#  undef __option_is_short
-#  undef __option_is_end
-# endif
-#endif /* Use extern inlines.  */
+__argp_short_program_name(const struct argp_state *state);
 
 #ifdef  __cplusplus
 }
