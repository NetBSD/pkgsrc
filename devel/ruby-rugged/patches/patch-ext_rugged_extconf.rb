$NetBSD: patch-ext_rugged_extconf.rb,v 1.4 2025/09/22 09:12:34 adam Exp $

Fix the build with system libgit2 1.9.0 https://github.com/libgit2/rugged/pull/985
Allow different minor version with libgit2.

--- ext/rugged/extconf.rb.orig	2025-09-22 08:34:21.937972643 +0000
+++ ext/rugged/extconf.rb
@@ -71,12 +71,12 @@ if arg_config("--use-system-libraries",
   major = minor = nil
 
   File.readlines(File.join(LIBGIT2_DIR, "include", "git2", "version.h")).each do |line|
-    if !major && (matches = line.match(/^#define LIBGIT2_VER_MAJOR\s+([0-9]+)$/))
+    if !major && (matches = line.match(/^#define LIBGIT2_VERSION_MAJOR\s+([0-9]+)$/))
       major = matches[1]
       next
     end
 
-    if !minor && (matches = line.match(/^#define LIBGIT2_VER_MINOR\s+([0-9]+)$/))
+    if !minor && (matches = line.match(/^#define LIBGIT2_VERSION_MINOR\s+([0-9]+)$/))
       minor = matches[1]
       next
     end
@@ -85,9 +85,9 @@ if arg_config("--use-system-libraries",
   end
 
   try_compile(<<-SRC) or abort "libgit2 version is not compatible, expected ~> #{major}.#{minor}.0"
-#include <git2/version.h>
+#include <git2.h>
 
-#if LIBGIT2_VER_MAJOR != #{major} || LIBGIT2_VER_MINOR != #{minor}
+#if LIBGIT2_VERSION_MAJOR != #{major}
 #error libgit2 version is not compatible
 #endif
   SRC
