$NetBSD: patch-lib_resolv.gemspec,v 1.1 2026/09/16 14:50:17 taca Exp $

Update resolv gem to 0.3.2.

--- lib/resolv.gemspec.orig	2026-07-16 04:03:30.000000000 +0000
+++ lib/resolv.gemspec
@@ -20,9 +20,8 @@ Gem::Specification.new do |spec|
   spec.metadata["homepage_uri"] = spec.homepage
   spec.metadata["source_code_uri"] = spec.homepage
 
-  spec.files         = Dir.chdir(File.expand_path('..', __FILE__)) do
-    `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^(test|spec|features)/}) }
-  end
+  excludes = %W[/.git* /bin /test /*file /#{File.basename(__FILE__)}]
+  spec.files = IO.popen(%W[git -C #{__dir__} ls-files -z --] + excludes.map {|e| ":^#{e}"}, &:read).split("\x0")
   spec.bindir        = "exe"
   spec.executables   = []
   spec.require_paths = ["lib"]
