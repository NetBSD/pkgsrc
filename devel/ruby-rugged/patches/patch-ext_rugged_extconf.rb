$NetBSD: patch-ext_rugged_extconf.rb,v 1.1 2022/09/03 15:06:52 taca Exp $

More general match.

--- ext/rugged/extconf.rb.orig	2022-07-30 14:13:40.613688545 +0000
+++ ext/rugged/extconf.rb
@@ -71,12 +71,12 @@ if arg_config("--use-system-libraries", 
   major = minor = nil
 
   File.readlines(File.join(LIBGIT2_DIR, "include", "git2", "version.h")).each do |line|
-    if !major && (matches = line.match(/^#define LIBGIT2_VER_MAJOR ([0-9]+)$/))
+    if !major && (matches = line.match(/^#define LIBGIT2_VER_MAJOR[ \t]+([0-9]+)$/))
       major = matches[1]
       next
     end
 
-    if !minor && (matches = line.match(/^#define LIBGIT2_VER_MINOR ([0-9]+)$/))
+    if !minor && (matches = line.match(/^#define LIBGIT2_VER_MINOR[ \t]+([0-9]+)$/))
       minor = matches[1]
       next
     end
