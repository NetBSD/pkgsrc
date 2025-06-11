$NetBSD: patch-gcc_c-family_c-opts.cc,v 1.2 2025/06/11 13:27:05 dkazankov Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/c-family/c-opts.cc.orig	2025-05-23 11:02:04.248196827 +0000
+++ gcc/c-family/c-opts.cc
@@ -1119,7 +1119,7 @@ c_common_post_options (const char **pfil
 
   if (flag_extern_tls_init)
     {
-      if (!TARGET_SUPPORTS_ALIASES || !SUPPORTS_WEAK)
+      if (!SUPPORTS_WEAK)
 	{
 	  /* Lazy TLS initialization for a variable in another TU requires
 	     alias and weak reference support.  */
