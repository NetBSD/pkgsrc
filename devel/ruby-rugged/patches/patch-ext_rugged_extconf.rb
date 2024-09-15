$NetBSD: patch-ext_rugged_extconf.rb,v 1.3 2024/09/15 16:35:00 taca Exp $

Allow different minor version with libgit2.

--- ext/rugged/extconf.rb.orig	2024-09-15 16:28:35.670037810 +0000
+++ ext/rugged/extconf.rb
@@ -87,7 +87,7 @@ if arg_config("--use-system-libraries", 
   try_compile(<<-SRC) or abort "libgit2 version is not compatible, expected ~> #{major}.#{minor}.0"
 #include <git2/version.h>
 
-#if LIBGIT2_VER_MAJOR != #{major} || LIBGIT2_VER_MINOR != #{minor}
+#if LIBGIT2_VER_MAJOR != #{major}
 #error libgit2 version is not compatible
 #endif
   SRC
