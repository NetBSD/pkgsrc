$NetBSD: patch-argp-help.c,v 1.2 2024/09/04 11:52:38 jperkin Exp $

Use getprogname() as short program name if available.
SunOS needs alloca.h.

--- argp-help.c.orig	2003-12-11 08:37:05.000000000 +0000
+++ argp-help.c
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
@@ -1725,6 +1729,8 @@ __argp_short_program_name(const struct a
   return program_invocation_short_name;
 #elif HAVE_DECL_PROGRAM_INVOCATION_NAME
   return __argp_basename(program_invocation_name);
+#elif HAVE_GETPROGNAME
+  return (char *)(uintptr_t)/*UNCONST*/getprogname();
 #else /* !HAVE_DECL_PROGRAM_INVOCATION_NAME */
   /* FIXME: What now? Miles suggests that it is better to use NULL,
      but currently the value is passed on directly to fputs_unlocked,
