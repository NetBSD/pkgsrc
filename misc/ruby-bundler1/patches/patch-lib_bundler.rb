$NetBSD: patch-lib_bundler.rb,v 1.1 2020/09/13 14:57:05 taca Exp $

Fix for CVE-2019-3881.

--- lib/bundler.rb.orig	2020-09-07 15:06:23.171036008 +0000
+++ lib/bundler.rb
@@ -170,8 +170,7 @@ module Bundler
         end
 
         if warning
-          Kernel.send(:require, "etc")
-          user_home = tmp_home_path(Etc.getlogin, warning)
+          user_home = tmp_home_path(warning)
           Bundler.ui.warn "#{warning}\nBundler will use `#{user_home}' as your home directory temporarily.\n"
           user_home
         else
@@ -180,21 +179,6 @@ module Bundler
       end
     end
 
-    def tmp_home_path(login, warning)
-      login ||= "unknown"
-      Kernel.send(:require, "tmpdir")
-      path = Pathname.new(Dir.tmpdir).join("bundler", "home")
-      SharedHelpers.filesystem_access(path) do |tmp_home_path|
-        unless tmp_home_path.exist?
-          tmp_home_path.mkpath
-          tmp_home_path.chmod(0o777)
-        end
-        tmp_home_path.join(login).tap(&:mkpath)
-      end
-    rescue RuntimeError => e
-      raise e.exception("#{warning}\nBundler also failed to create a temporary home directory at `#{path}':\n#{e}")
-    end
-
     def user_bundle_path(dir = "home")
       env_var, fallback = case dir
                           when "home"
@@ -555,6 +539,17 @@ EOF
       Bundler.rubygems.clear_paths
     end
 
+    def tmp_home_path(warning)
+      Kernel.send(:require, "tmpdir")
+      SharedHelpers.filesystem_access(Dir.tmpdir) do
+        path = Bundler.tmp
+        at_exit { Bundler.rm_rf(path) }
+        path
+      end
+    rescue RuntimeError => e
+      raise e.exception("#{warning}\nBundler also failed to create a temporary home directory':\n#{e}")
+    end
+
     # @param env [Hash]
     def with_env(env)
       backup = ENV.to_hash
