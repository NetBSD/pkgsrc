$NetBSD: patch-argp-help.c,v 1.1 2024/08/06 18:50:08 riastradh Exp $

Use getprogname() as short program name if available.

--- argp-help.c.orig	2003-12-11 08:37:05.000000000 +0000
+++ argp-help.c
@@ -1725,6 +1725,8 @@ __argp_short_program_name(const struct a
   return program_invocation_short_name;
 #elif HAVE_DECL_PROGRAM_INVOCATION_NAME
   return __argp_basename(program_invocation_name);
+#elif HAVE_GETPROGNAME
+  return (char *)(uintptr_t)/*UNCONST*/getprogname();
 #else /* !HAVE_DECL_PROGRAM_INVOCATION_NAME */
   /* FIXME: What now? Miles suggests that it is better to use NULL,
      but currently the value is passed on directly to fputs_unlocked,
