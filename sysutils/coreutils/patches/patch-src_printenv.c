$NetBSD: patch-src_printenv.c,v 1.1 2026/09/25 07:14:32 wiz Exp $

env,printenv: only quote when outputting to terminals
To support albeit non-robust but existing use cases like:

  env | grep SPARK_JAVA_OPT_ | sort -t_ -k4 -n |
   sed 's/[^=]*=\(.*\)/\1/g' > java_opts.txt
  readarray -t SPARK_EXECUTOR_JAVA_OPTS < java_opts.txt
  ...
  CMD=("${JAVA_HOME}/bin/java" "${SPARK_EXECUTOR_JAVA_OPTS[@]}" ...)

https://github.com/coreutils/coreutils/commit/782a1e5bc2090212273bb731dceee2cc2a071e54

--- src/printenv.c.orig	2026-09-01 21:37:43.000000000 +0000
+++ src/printenv.c
@@ -113,7 +113,7 @@ main (int argc, char **argv)
   bool quote_output = false;
   idx_t const n_args = argc - optind;
 
-  if (!opt_nul_terminate_output && (n_args <= 0 || isatty (STDOUT_FILENO)))
+  if (!opt_nul_terminate_output && isatty (STDOUT_FILENO))
     {
       int qs = getenv_quoting_style ();
       if (qs < 0)
