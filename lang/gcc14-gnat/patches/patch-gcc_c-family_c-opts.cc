$NetBSD: patch-gcc_c-family_c-opts.cc,v 1.1 2025/04/25 19:35:10 dkazankov Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/c-family/c-opts.cc
+++ gcc/c-family/c-opts.cc
@@ -1119,7 +1119,7 @@ c_common_post_options (const char **pfilename)

   if (flag_extern_tls_init)
     {
-      if (!TARGET_SUPPORTS_ALIASES || !SUPPORTS_WEAK)
+      if (!SUPPORTS_WEAK)
 	{
 	  /* Lazy TLS initialization for a variable in another TU requires
 	     alias and weak reference support.  */
