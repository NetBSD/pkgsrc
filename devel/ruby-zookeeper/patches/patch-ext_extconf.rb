$NetBSD: patch-ext_extconf.rb,v 1.2 2023/01/03 13:56:31 taca Exp $

Link pkgsrc libzookeeper instead of the embedded build.

--- ext/extconf.rb.orig	2023-01-02 08:23:51.434066414 +0000
+++ ext/extconf.rb
@@ -2,30 +2,6 @@ require 'mkmf'
 require 'rbconfig'
 require 'fileutils'
 
-HERE = File.expand_path(File.dirname(__FILE__))
-BUNDLE = Dir.glob("zkc-*.tar.gz").sort.last
-ZKC_VERSION = BUNDLE[/(zkc-.*?)\.tar.gz$/, 1]
-PATCHES = Dir.glob("patches/#{ZKC_VERSION}*.patch")
-
-BUNDLE_PATH = File.join(HERE, ZKC_VERSION, 'c')
-
-$EXTRA_CONF = ''
-
-# CLANG!!!! jeez, if apple would only *stop* "thinking different"
-if cc = RbConfig::CONFIG['CC'] && cc =~ /^gcc/
-  $CC = cc
-  $EXTRA_CONF = "#{$EXTRA_CONF} CC=#{$CC}"
-end
-
-$CFLAGS = "#{$CFLAGS}".gsub("$(cflags)", "").gsub("-arch ppc", "")
-$LDFLAGS = "#{$LDFLAGS}".gsub("$(ldflags)", "").gsub("-arch ppc", "")
-$CXXFLAGS = " -std=gnu++98 #{$CFLAGS}"
-$CPPFLAGS = $ARCH_FLAG = ""
-
-if RUBY_VERSION == '1.8.7'
-  $CFLAGS << ' -DZKRB_RUBY_187'
-end
-
 ZK_DEBUG = (ENV['DEBUG'] or ARGV.any? { |arg| arg == '--debug' })
 ZK_DEV = ENV['ZK_DEV']
 DEBUG_CFLAGS = " -O0 -ggdb3 -DHAVE_DEBUG -fstack-protector-all"
@@ -37,63 +13,9 @@ if ZK_DEBUG
   $CFLAGS << DEBUG_CFLAGS
 end
 
-$includes = " -I#{HERE}/include"
-$libraries = " -L#{HERE}/lib -L#{RbConfig::CONFIG['libdir']}"
-$CFLAGS = "#{$includes} #{$libraries} #{$CFLAGS}"
-$LDFLAGS = "#{$libraries} #{$LDFLAGS}"
-$LIBPATH = ["#{HERE}/lib"]
-$DEFLIBPATH = []
-
-def safe_sh(cmd)
-  puts cmd
-  system(cmd)
-  unless $?.exited? and $?.success?
-    raise "command failed! #{cmd}"
-  end
-end
-
-Dir.chdir(HERE) do
-  if File.exist?("lib")
-    puts "Zkc already built; run 'rake clobber' in ext/ first if you need to rebuild."
-  else
-    puts "Building zkc."
-
-    unless File.exists?('c')
-      safe_sh "tar xzf #{BUNDLE} 2>&1"
-      PATCHES.each do |patch|
-        safe_sh "patch -p0 < #{patch} 2>&1"
-      end
-    end
-
-    # clean up stupid apple rsrc fork bullshit
-    FileUtils.rm_f(Dir['**/._*'].select{|p| test(?f, p)})
-
-    Dir.chdir(BUNDLE_PATH) do
-      configure = "./configure --prefix=#{HERE} --with-pic --without-cppunit --disable-dependency-tracking #{$EXTRA_CONF} 2>&1"
-      configure = "env CFLAGS='#{DEBUG_CFLAGS}' #{configure}" if ZK_DEBUG
-
-      safe_sh(configure)
-      safe_sh("make  2>&1")
-      safe_sh("make install 2>&1")
-    end
-
-    system("rm -rf #{BUNDLE_PATH}") unless ZK_DEBUG or ZK_DEV
-  end
-end
-
-# Absolutely prevent the linker from picking up any other zookeeper_mt
-Dir.chdir("#{HERE}/lib") do
-  %w[st mt].each do |stmt|
-    %w[a la dylib].each do |ext|
-      origin_lib_name = "libzookeeper_#{stmt}.#{ext}"
-      dest_lib_name = "libzookeeper_#{stmt}_gem.#{ext}"
-      system("cp -f #{origin_lib_name} #{dest_lib_name}") if File.exists?(origin_lib_name)
-    end
-  end
-end
-
-# -lm must come after lzookeeper_st_gem to ensure proper link
-$LIBS << " -lzookeeper_st_gem -lm"
+build_root = ENV['PREFIX']
+ldflags = ENV['LDFLAGS']
+$LIBS << " -lzookeeper_st #{ldflags} -lm"
 
 have_func('rb_thread_blocking_region')
 have_func('rb_thread_fd_select')
