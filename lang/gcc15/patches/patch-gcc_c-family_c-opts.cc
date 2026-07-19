$NetBSD: patch-gcc_c-family_c-opts.cc,v 1.1 2026/07/19 11:17:42 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/c-family/c-opts.cc.orig	2026-06-12 06:09:06.074517522 +0000
+++ gcc/c-family/c-opts.cc
@@ -1192,7 +1192,7 @@ c_common_post_options (const char **pfil

   if (flag_extern_tls_init)
     {
-      if (!TARGET_SUPPORTS_ALIASES || !SUPPORTS_WEAK)
+      if (!SUPPORTS_WEAK)
 	{
 	  /* Lazy TLS initialization for a variable in another TU requires
 	     alias and weak reference support.  */
