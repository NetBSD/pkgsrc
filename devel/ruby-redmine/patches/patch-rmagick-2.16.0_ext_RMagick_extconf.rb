$NetBSD: patch-rmagick-2.16.0_ext_RMagick_extconf.rb,v 1.1 2020/05/06 08:15:01 taca Exp $

* Partly use rmagick 4.1.2's extconf.rb to build with newer ImageMagick6.

--- rmagick-2.16.0/ext/RMagick/extconf.rb.orig	2020-04-28 14:51:55.125428720 +0000
+++ rmagick-2.16.0/ext/RMagick/extconf.rb
@@ -2,27 +2,43 @@ lib_dir = File.expand_path('../../lib', 
 $LOAD_PATH.unshift(lib_dir) unless $LOAD_PATH.include?(lib_dir)
 require 'rubygems'
 require 'mkmf'
-require 'date'
 
 module RMagick
   class Extconf
     require 'rmagick/version'
     RMAGICK_VERS = ::Magick::VERSION
     MIN_RUBY_VERS = ::Magick::MIN_RUBY_VERSION
-    MIN_RUBY_VERS_NO = MIN_RUBY_VERS.tr('.','').to_i
 
     attr_reader :headers
+
     def initialize
-      configure_compile_options
+      @stdout = $stdout.dup
+
+      setup_pkg_config_path
       assert_can_compile!
+      configure_compile_options
       configure_headers
     end
 
+    def setup_pkg_config_path
+      return if RUBY_PLATFORM =~ /mswin|mingw/
+
+      if find_executable('brew')
+        pkg_config_path = "#{`brew --prefix imagemagick@6`.strip}/lib/pkgconfig"
+      elsif find_executable('pacman')
+        pkg_config_path = '/usr/lib/imagemagick6/pkgconfig'
+      else
+        return
+      end
+
+      pkg_config_paths = ENV['PKG_CONFIG_PATH'].to_s.split(':')
+      if File.exist?(pkg_config_path) && !pkg_config_paths.include?(pkg_config_path)
+        ENV['PKG_CONFIG_PATH'] = [ENV['PKG_CONFIG_PATH'], pkg_config_path].compact.join(':')
+      end
+    end
+
     def configured_compile_options
       {
-        :magick_config => $magick_config,
-        :with_magick_wand => $with_magick_wand,
-        :pkg_config    => $pkg_config,
         :magick_version => $magick_version,
         :local_libs     => $LOCAL_LIBS,
         :cflags         => $CFLAGS,
@@ -34,15 +50,19 @@ module RMagick
     end
 
     def configure_headers
-      #headers = %w{assert.h ctype.h errno.h float.h limits.h math.h stdarg.h stddef.h stdint.h stdio.h stdlib.h string.h time.h}
+      @headers = %w[assert.h ctype.h stdio.h stdlib.h math.h time.h sys/types.h]
       @headers = %w{assert.h ctype.h stdio.h stdlib.h math.h time.h}
       headers << 'stdint.h' if have_header('stdint.h')  # defines uint64_t
       headers << 'sys/types.h' if have_header('sys/types.h')
 
       if have_header('wand/MagickWand.h')
         headers << 'wand/MagickWand.h'
+      elsif have_header('MagickCore/MagickCore.h')
+        headers << 'MagickCore/MagickCore.h'
+      elsif have_header('magick/MagickCore.h')
+        headers << 'magick/MagickCore.h'
       else
-        exit_failure "\nCan't install RMagick #{RMAGICK_VERS}. Can't find MagickWand.h."
+        exit_failure "Can't install RMagick #{RMAGICK_VERS}. Can't find magick/MagickCore.h."
       end
     end
 
@@ -50,159 +70,94 @@ module RMagick
       # Magick-config is not available on Windows
       if RUBY_PLATFORM !~ /mswin|mingw/
 
-        # Check for compiler. Extract first word so ENV['CC'] can be a program name with arguments.
-        config = defined?(RbConfig) ? ::RbConfig : ::Config
-        cc = (ENV['CC'] || config::CONFIG['CC'] || 'gcc').split(' ').first
-        unless find_executable(cc)
-          exit_failure "No C compiler found in ${ENV['PATH']}. See mkmf.log for details."
-        end
-
-        # ugly way to handle which config tool we're going to use...
-        $with_magick_wand = false
-        $magick_config = false
-        $pkg_config = false
-
-        # Check for Magick-config
-        if find_executable('Magick-config') && !has_graphicsmagick_libmagick_dev_compat?
-          $magick_config = true
-          $magick_version = `Magick-config --version`[/^(\d+\.\d+\.\d+)/]
-        elsif find_executable('pkg-config')
-          $pkg_config = true
-          $magick_version = `pkg-config MagickCore --modversion`[/^(\d+\.\d+\.\d+)/]
-        else
-          exit_failure "Can't install RMagick #{RMAGICK_VERS}. Can't find Magick-config or pkg-config in #{ENV['PATH']}\n"
-        end
-
         check_multiple_imagemagick_versions
         check_partial_imagemagick_versions
 
-        # Ensure minimum ImageMagick version
-        # Check minimum ImageMagick version if possible
-        checking_for("outdated ImageMagick version (<= #{Magick::MIN_IM_VERSION})") do
-          Logging.message("Detected ImageMagick version: #{$magick_version}\n")
+        # Save flags
+        $CFLAGS     = "#{ENV['CFLAGS']} "   + `pkg-config --cflags #{$magick_package}`.chomp
+        $CPPFLAGS   = "#{ENV['CPPFLAGS']} " + `pkg-config --cflags #{$magick_package}`.chomp
+        $LDFLAGS    = "#{ENV['LDFLAGS']} "  + `pkg-config --libs #{$magick_package}`.chomp
+        $LOCAL_LIBS = "#{ENV['LIBS']} "     + `pkg-config --libs #{$magick_package}`.chomp
 
-          if Gem::Version.new($magick_version) < Gem::Version.new(Magick::MIN_IM_VERSION)
-            exit_failure "Can't install RMagick #{RMAGICK_VERS}. You must have ImageMagick #{Magick::MIN_IM_VERSION} or later.\n"
-          end
-        end
+        configure_archflags_for_osx($magick_package) if RUBY_PLATFORM =~ /darwin/ # osx
 
-        # From ImageMagick 6.9 binaries are split to two and we have to use
-        # MagickWand instead of MagickCore
-        checking_for("presence of MagickWand API (ImageMagick version >= #{Magick::MIN_WAND_VERSION})") do
-          $with_magick_wand = Gem::Version.new($magick_version) >= Gem::Version.new(Magick::MIN_WAND_VERSION)
-          if $with_magick_wand
-            Logging.message('Detected 6.9+ version, using MagickWand API')
-          else
-            Logging.message('Older version detected, using MagickCore API')
-          end
-        end
+      elsif RUBY_PLATFORM =~ /mingw/ # mingw
 
-        # either set flags using Magick-config, MagickWand-config or pkg-config (new Debian default)
-        if $with_magick_wand
-          if $magick_config
-            # Save flags
-            $CFLAGS     = ENV['CFLAGS'].to_s   + ' ' + `MagickWand-config --cflags`.chomp
-            $CPPFLAGS   = ENV['CPPFLAGS'].to_s + ' ' + `MagickWand-config --cppflags`.chomp
-            $LDFLAGS    = ENV['LDFLAGS'].to_s  + ' ' + `MagickWand-config --ldflags`.chomp
-            $LOCAL_LIBS = ENV['LIBS'].to_s     + ' ' + `MagickWand-config --libs`.chomp
-          end
+        dir_paths = search_paths_for_library_for_windows
+        $CPPFLAGS = %(-I"#{dir_paths[:include]}")
+        $LDFLAGS = %(-L"#{dir_paths[:lib]}")
+        $LDFLAGS << ' -lucrt' if Gem::Version.new(RUBY_VERSION) >= Gem::Version.new('2.4.0')
 
-          if $pkg_config
-            # Save flags
-            $CFLAGS     = ENV['CFLAGS'].to_s   + ' ' + `pkg-config --cflags MagickWand`.chomp
-            $CPPFLAGS   = ENV['CPPFLAGS'].to_s + ' ' + `pkg-config --cflags MagickWand`.chomp
-            $LDFLAGS    = ENV['LDFLAGS'].to_s  + ' ' + `pkg-config --libs MagickWand`.chomp
-            $LOCAL_LIBS = ENV['LIBS'].to_s     + ' ' + `pkg-config --libs MagickWand`.chomp
-          end
-        else
-          if $magick_config
-            # Save flags
-            $CFLAGS     = ENV['CFLAGS'].to_s   + ' ' + `Magick-config --cflags`.chomp
-            $CPPFLAGS   = ENV['CPPFLAGS'].to_s + ' ' + `Magick-config --cppflags`.chomp
-            $LDFLAGS    = ENV['LDFLAGS'].to_s  + ' ' + `Magick-config --ldflags`.chomp
-            $LOCAL_LIBS = ENV['LIBS'].to_s     + ' ' + `Magick-config --libs`.chomp
-          end
+        have_library(im_version_at_least?('7.0.0') ? 'CORE_RL_MagickCore_' : 'CORE_RL_magick_')
 
-          if $pkg_config
-            # Save flags
-            $CFLAGS     = ENV['CFLAGS'].to_s   + ' ' + `pkg-config --cflags MagickCore`.chomp
-            $CPPFLAGS   = ENV['CPPFLAGS'].to_s + ' ' + `pkg-config --cflags MagickCore`.chomp
-            $LDFLAGS    = ENV['LDFLAGS'].to_s  + ' ' + `pkg-config --libs MagickCore`.chomp
-            $LOCAL_LIBS = ENV['LIBS'].to_s     + ' ' + `pkg-config --libs MagickCore`.chomp
-          end
-        end
+      else # mswin
 
-        if RUBY_PLATFORM =~ /darwin/ # osx
-          set_archflags_for_osx
-        end
+        dir_paths = search_paths_for_library_for_windows
+        $CPPFLAGS << %( -I"#{dir_paths[:include]}")
+        $LDFLAGS << %( -libpath:"#{dir_paths[:lib]}")
+        $LDFLAGS << ' -libpath:ucrt' if Gem::Version.new(RUBY_VERSION) >= Gem::Version.new('2.4.0')
 
-      elsif RUBY_PLATFORM =~ /mingw/  # mingw
+        $LOCAL_LIBS = im_version_at_least?('7.0.0') ? 'CORE_RL_MagickCore_.lib' : 'CORE_RL_magick_.lib'
 
-        `identify -version` =~ /Version: ImageMagick (\d+\.\d+\.\d+)-+\d+ /
-        abort 'Unable to get ImageMagick version' unless $1
-        $magick_version = $1
-        unless have_library('CORE_RL_magick_')
-          search_paths_for_library_for_mingw
-        end
-        have_library('X11')
+      end
+
+      $CFLAGS << (have_macro('__GNUC__') ? ' -std=gnu99' : ' -std=c99')
+    end
 
-      else  # mswin
+    def exit_failure(msg)
+      msg = "ERROR: #{msg}"
 
-        `identify -version` =~ /Version: ImageMagick (\d+\.\d+\.\d+)-+\d+ /
-        abort 'Unable to get ImageMagick version' unless $1
-        $magick_version = $1
-        $CFLAGS = '-W3'
-        $CPPFLAGS = %Q{-I"C:\\Program Files\\Microsoft Platform SDK for Windows Server 2003 R2\\Include" -I"C:\\Program Files\\ImageMagick-#{$magick_version}-Q8\\include"}
-        # The /link option is required by the Makefile but causes warnings in the mkmf.log file.
-        $LDFLAGS = %Q{/link /LIBPATH:"C:\\Program Files\\Microsoft Platform SDK for Windows Server 2003 R2\\Lib" /LIBPATH:"C:\\Program Files\\ImageMagick-#{$magick_version}-Q8\\lib" /LIBPATH:"C:\\ruby\\lib"}
-        $LOCAL_LIBS = 'CORE_RL_magick_.lib'
-        have_library('X11')
+      Logging.message msg
 
+      @stdout.puts "\n\n"
+      if ENV['NO_COLOR']
+        @stdout.puts msg
+      else
+        @stdout.print "\e[31m\e[1m#{msg}\e[0m"
       end
+      @stdout.puts "\n\n"
+      @stdout.flush
+
+      exit(1)
     end
 
-    # Test for a specific value in an enum type
-    def have_enum_value(enum, value, headers=nil, &b)
-      checking_for "#{enum}.#{value}" do
-        if try_compile(<<"SRC", &b)
-#{COMMON_HEADERS}
-#{cpp_include(headers)}
-/*top*/
-int main() { #{enum} t = #{value}; t = t; return 0; }
-SRC
-          $defs.push(format('-DHAVE_ENUM_%s', value.upcase))
-          true
-        else
-          false
-        end
+    def determine_imagemagick_package
+      packages = `pkg-config --list-all`.scan(/(ImageMagick\-[\.A-Z0-9]+) .*/).flatten
+
+      # For ancient version of ImageMagick 6 we need a different regex
+      if packages.empty?
+        packages = `pkg-config --list-all`.scan(/(ImageMagick) .*/).flatten
       end
-    end
 
-    # Test for multiple values of the same enum type
-    def have_enum_values(enum, values, headers=nil, &b)
-      values.each do |value|
-        have_enum_value(enum, value, headers, &b)
+      if packages.empty?
+        exit_failure "Can't install RMagick #{RMAGICK_VERS}. Can't find ImageMagick with pkg-config\n"
+      end
+
+      if packages.length > 1
+
+        im7_packages = packages.grep(/\AImageMagick-7/)
+
+        if im7_packages.any?
+          checking_for('forced use of ImageMagick 6') do
+            if ENV['USE_IMAGEMAGICK_6']
+              packages -= im7_packages
+              true
+            else
+              packages = im7_packages
+              false
+            end
+          end
+        end
       end
-    end
 
-    def has_graphicsmagick_libmagick_dev_compat?
-      config_path = `which Magick-config`.chomp
-      if File.exist?(config_path) &&
-         File.symlink?(config_path) &&
-         File.readlink(config_path) =~ /GraphicsMagick/
-        msg = 'Found a graphicsmagick-libmagick-dev-compat installation.'
+      if packages.length > 1
+        package_lines = packages.map { |package| " - #{package}" }.join("\n")
+        msg = "\nWarning: Found more than one ImageMagick installation. This could cause problems at runtime.\n#{package_lines}\n\n"
         Logging.message msg
-        message msg+"\n"
-        true
-      else
-        false
+        message msg
       end
-    end
 
-    def exit_failure(msg)
-      Logging.message msg
-      message msg+"\n"
-      exit(1)
+      packages.first
     end
 
     # Seems like lots of people have multiple versions of ImageMagick installed.
@@ -211,22 +166,22 @@ SRC
       path = ENV['PATH'].split(File::PATH_SEPARATOR)
       path.each do |dir|
         file = File.join(dir, 'Magick-config')
-        if File.executable? file
-          vers = `#{file} --version`.chomp.strip
-          prefix = `#{file} --prefix`.chomp.strip
-          versions << [vers, prefix, dir]
-        end
+        next unless File.executable? file
+
+        vers = `#{file} --version`.chomp.strip
+        prefix = `#{file} --prefix`.chomp.strip
+        versions << [vers, prefix, dir]
       end
       versions.uniq!
-      if versions.size > 1
-        msg = "\nWarning: Found more than one ImageMagick installation. This could cause problems at runtime.\n"
-        versions.each do |vers, prefix, dir|
-          msg << "         #{dir}/Magick-config reports version #{vers} is installed in #{prefix}\n"
-        end
-        msg << "Using #{versions[0][0]} from #{versions[0][1]}.\n\n"
-        Logging.message msg
-        message msg
+      return unless versions.size > 1
+
+      msg = "\nWarning: Found more than one ImageMagick installation. This could cause problems at runtime.\n"
+      versions.each do |vers, prefix, dir|
+        msg << "         #{dir}/Magick-config reports version #{vers} is installed in #{prefix}\n"
       end
+      msg << "Using #{versions[0][0]} from #{versions[0][1]}.\n\n"
+      Logging.message msg
+      message msg
     end
 
     # Ubuntu (maybe other systems) comes with a partial installation of
@@ -236,280 +191,165 @@ SRC
     def check_partial_imagemagick_versions
       prefix = config_string('prefix') || ''
       matches = [
-        prefix+'/lib/lib?agick*',
-        prefix+'/include/ImageMagick',
-        prefix+'/bin/Magick-config',
+        prefix + '/lib/lib?agick*',
+        prefix + '/include/ImageMagick-6',
+        prefix + '/bin/Magick-config6'
       ].map do |file_glob|
         Dir.glob(file_glob)
       end
-      matches.delete_if { |arr| arr.empty? }
-      if 0 < matches.length && matches.length < 3
-        msg = "\nWarning: Found a partial ImageMagick installation. Your operating system likely has some built-in ImageMagick libraries but not all of ImageMagick. This will most likely cause problems at both compile and runtime.\nFound partial installation at: "+prefix+"\n"
-        Logging.message msg
-        message msg
-      end
+      matches.delete_if(&:empty?)
+      return unless !matches.empty? && matches.length < 3
+
+      msg = <<~MESSAGE
+
+        Warning: Found a partial ImageMagick installation. Your operating
+        system likely has some built-in ImageMagick libraries but not all of
+        ImageMagick. This will most likely cause problems at both compile and
+        runtime.
+        Found partial installation at: #{prefix}
+
+      MESSAGE
+
+      Logging.message msg
+      message msg
     end
 
     # issue #169
     # set ARCHFLAGS appropriately for OSX
-    def set_archflags_for_osx
-      archflags = []
-      fullpath = `which convert`
-      fileinfo = `file #{fullpath}`
+    def configure_archflags_for_osx(magick_package)
+      return unless `pkg-config #{magick_package} --libs-only-L`.match(%r{-L(.+)/lib})
+
+      imagemagick_dir = Regexp.last_match(1)
+      command = Dir.glob(File.join(imagemagick_dir, "bin/*")).select { |file| File.executable? file }.first
+      fileinfo = `file #{command}`
 
       # default ARCHFLAGS
       archs = $ARCH_FLAG.scan(/-arch\s+(\S+)/).flatten
 
+      archflags = []
       archs.each do |arch|
-        if fileinfo.include?(arch)
-          archflags << "-arch #{arch}"
-        end
+        archflags << "-arch #{arch}" if fileinfo.include?(arch)
       end
 
-      if archflags.length != 0
-        $ARCH_FLAG = archflags.join(' ')
-      end
+      $ARCH_FLAG = archflags.join(' ') unless archflags.empty?
     end
 
-    def search_paths_for_library_for_mingw
+    def search_paths_for_library_for_windows
       msg = 'searching PATH for the ImageMagick library...'
       Logging.message msg
-      message msg+"\n"
+      message msg + "\n"
 
       found_lib = false
+      dir_paths = {}
 
       paths = ENV['PATH'].split(File::PATH_SEPARATOR)
       paths.each do |dir|
         lib = File.join(dir, 'lib')
-        lib_file = File.join(lib, 'CORE_RL_magick_.lib')
-        if File.exist?(lib_file)
-          $CPPFLAGS = %Q{-I"#{File.join(dir, 'include')}"}
-          $LDFLAGS = %Q{-L"#{lib}"}
-          found_lib = have_library('CORE_RL_magick_')
-          break if found_lib
-        end
-      end
+        lib_file = File.join(lib, im_version_at_least?('7.0.0') ? 'CORE_RL_MagickCore_.lib' : 'CORE_RL_magick_.lib')
+        next unless File.exist?(lib_file)
+
+        dir_paths[:include] = File.join(dir, 'include')
+        dir_paths[:lib] = lib
 
-      unless found_lib
-        exit_failure <<END_MINGW
-Can't install RMagick #{RMAGICK_VERS}.
-Can't find the ImageMagick library.
-Retry with '--with-opt-dir' option.
-Usage: gem install rmagick -- '--with-opt-dir=\"[path to ImageMagick]\"'
-e.g.
-  gem install rmagick -- '--with-opt-dir=\"C:\Program Files\ImageMagick-6.9.1-Q16\"'
-END_MINGW
+        found_lib = true
+        break
       end
+
+      return dir_paths if found_lib
+
+      exit_failure <<~END_MINGW
+        Can't install RMagick #{RMAGICK_VERS}.
+        Can't find the ImageMagick library.
+        Retry with '--with-opt-dir' option.
+        Usage: gem install rmagick -- '--with-opt-dir=\"[path to ImageMagick]\"'
+        e.g.
+          gem install rmagick -- '--with-opt-dir=\"C:\Program Files\ImageMagick-6.9.1-Q16\"'
+      END_MINGW
     end
 
     def assert_can_compile!
-      assert_not_windows!
       assert_minimum_ruby_version!
       assert_has_dev_libs!
-    end
 
-    def assert_not_windows!
-      if RUBY_PLATFORM =~ /mswin/
-        abort <<END_MSWIN
-+----------------------------------------------------------------------------+
-| This rmagick gem is for use only on Linux, BSD, OS X, and similar systems  |
-| that have a gnu or similar toolchain installed. The rmagick-win32 gem is a |
-| pre-compiled version of RMagick bundled with ImageMagick for use on        |
-| Microsoft Windows systems. The rmagick-win32 gem is available on RubyForge.|
-| See http://rmagick.rubyforge.org/install-faq.html for more information.    |
-+----------------------------------------------------------------------------+
-END_MSWIN
-      end
+      # Check for compiler. Extract first word so ENV['CC'] can be a program name with arguments.
+      cc = (ENV['CC'] || RbConfig::CONFIG['CC'] || 'gcc').split(' ').first
+      exit_failure "No C compiler found in ${ENV['PATH']}. See mkmf.log for details." unless find_executable(cc)
     end
 
     def assert_minimum_ruby_version!
-      unless checking_for("Ruby version >= #{MIN_RUBY_VERS}") do
-        version = RUBY_VERSION.tr('.','').to_i
-        version >= MIN_RUBY_VERS_NO
-      end
-        exit_failure "Can't install RMagick #{RMAGICK_VERS}. Ruby #{MIN_RUBY_VERS} or later required.\n"
+      supported = checking_for("Ruby version >= #{MIN_RUBY_VERS}") do
+        Gem::Version.new(RUBY_VERSION) >= Gem::Version.new(MIN_RUBY_VERS)
       end
+
+      exit_failure "Can't install RMagick #{RMAGICK_VERS}. Ruby #{MIN_RUBY_VERS} or later required.\n" unless supported
     end
 
     def assert_has_dev_libs!
+      failure_message = <<~END_FAILURE
+        Can't install RMagick #{RMAGICK_VERS}.
+        Can't find the ImageMagick library or one of the dependent libraries.
+        Check the mkmf.log file for more detailed information.
+      END_FAILURE
+
       if RUBY_PLATFORM !~ /mswin|mingw/
+        unless find_executable('pkg-config')
+          exit_failure "Can't install RMagick #{RMAGICK_VERS}. Can't find pkg-config in #{ENV['PATH']}\n"
+        end
 
-        # check for pkg-config if Magick-config doesn't exist
-        if $magick_config && `Magick-config --libs`[/\bl\s*(MagickCore|Magick)6?\b/]
-        elsif $pkg_config && `pkg-config --libs MagickCore`[/\bl\s*(MagickCore|Magick)6?\b/]
-        else
-            exit_failure "Can't install RMagick #{RMAGICK_VERS}. " \
-                   "Can't find the ImageMagick library or one of the dependent libraries. " \
-                   "Check the mkmf.log file for more detailed information.\n"
+        unless `pkg-config --libs MagickCore`[/\bl\s*(MagickCore|Magick)6?\b/]
+          exit_failure failure_message
         end
+
+        $magick_package = determine_imagemagick_package
+        $magick_version = `pkg-config #{$magick_package} --modversion`[/^(\d+\.\d+\.\d+)/]
+      else
+        `#{magick_command} -version` =~ /Version: ImageMagick (\d+\.\d+\.\d+)-+\d+ /
+        $magick_version = Regexp.last_match(1)
+        exit_failure failure_message unless $magick_version
+      end
+
+      # Ensure minimum ImageMagick version
+      # Check minimum ImageMagick version if possible
+      checking_for("outdated ImageMagick version (<= #{Magick::MIN_IM_VERSION})") do
+        Logging.message("Detected ImageMagick version: #{$magick_version}\n")
+
+        exit_failure "Can't install RMagick #{RMAGICK_VERS}. You must have ImageMagick #{Magick::MIN_IM_VERSION} or later.\n" if Gem::Version.new($magick_version) < Gem::Version.new(Magick::MIN_IM_VERSION)
       end
     end
 
     def create_header_file
-      have_func('snprintf', headers)
-      ['AcquireImage',                   # 6.4.1
-       'AffinityImage',                  # 6.4.3-6
-       'AffinityImages',                 # 6.4.3-6
-       'AutoGammaImageChannel',          # 6.5.5-1
-       'AutoLevelImageChannel',          # 6.5.5-1
-       'BlueShiftImage',                 # 6.5.4-3
-       'ColorMatrixImage',               # 6.6.1-0
-       'ConstituteComponentTerminus',    # 6.5.7-9
-       'DeskewImage',                    # 6.4.2-5
-       'DestroyConstitute',              # 6.5.7-9(deprecated)
-       'EncipherImage',                  # 6.3.8-6
-       'EqualizeImageChannel',           # 6.3.6-9
-       'EvaluateImages',                 # 6.8.6-4
-       'FloodfillPaintImage',            # 6.3.7
-       'FunctionImageChannel',           # 6.4.8-8
-       'GetAuthenticIndexQueue',         # 6.4.5-6
-       'GetAuthenticPixels',             # 6.4.5-6
-       'GetImageAlphaChannel',           # 6.3.9-2
-       'GetMagickFeatures',              # 6.5.7-1
-       'GetVirtualPixels',               # 6.4.5-6
-       'LevelImageColors',               # 6.4.2
-       'LevelColorsImageChannel',        # 6.5.6-4
-       'LevelizeImageChannel',           # 6.4.2
-       'LiquidRescaleImage',             # 6.3.8-2
-       'MagickLibAddendum',              # 6.5.9-1
-       'OpaquePaintImageChannel',        # 6.3.7-10
-       'QueueAuthenticPixels',           # 6.4.5-6
-       'RemapImage',                     # 6.4.4-0
-       'RemapImages',                    # 6.4.4-0
-       'RemoveImageArtifact',            # 6.3.6
-       'RotationalBlurImage',            # 6.8.8-9
-       'RotationalBlurImageChannel',     # 6.8.8-9
-       'SelectiveBlurImageChannel',      # 6.5.0-3
-       'SetImageAlphaChannel',           # 6.3.6-9
-       'SetImageArtifact',               # 6.3.6
-       'SetMagickMemoryMethods',         # 6.4.1
-       'SparseColorImage',               # 6.3.6-?
-       'StatisticImage',                 # 6.6.8-6
-       'SyncAuthenticPixels',            # 6.4.5-6
-       'TransformImageColorspace',       # 6.5.1
-       'TransparentPaintImage',          # 6.3.7-10
-       'TransparentPaintImageChroma'     # 6.4.5-6
-      ].each do |func|
-        have_func(func, headers)
-      end
+      ruby_api = [
+        'rb_gc_adjust_memory_usage' # Ruby 2.4.0
+      ]
+      memory_api = %w[
+        posix_memalign
+        malloc_usable_size
+        malloc_size
+        _aligned_msize
+      ]
+      imagemagick_api = [
+        'GetImageChannelEntropy', # 6.9.0-0
+        'SetImageGray', # 6.9.1-10
+        'SetMagickAlignedMemoryMethods' # 7.0.9-0
+      ]
 
-      checking_for('QueryMagickColorname() new signature')  do
-        if try_compile(<<"SRC")
-#{COMMON_HEADERS}
-#{cpp_include(headers)}
-/*top*/
-int main() {
-  MagickBooleanType okay;
-  Image *image;
-  MagickPixelPacket *color;
-  char *name;
-  ExceptionInfo *exception;
-  okay = QueryMagickColorname(image, color, SVGCompliance, name, exception);
-  return 0;
-  }
-SRC
-          $defs.push('-DHAVE_NEW_QUERYMAGICKCOLORNAME')
-          true
-        else
-          false
-        end
+      check_api = ruby_api + memory_api + imagemagick_api
+      check_api.each do |func|
+        have_func(func, headers)
       end
 
-      have_struct_member('Image', 'type', headers)          # ???
-      have_struct_member('DrawInfo', 'kerning', headers)    # 6.4.7-8
-      have_struct_member('DrawInfo', 'interline_spacing', headers)   # 6.5.5-8
-      have_struct_member('DrawInfo', 'interword_spacing', headers)   # 6.4.8-0
-      have_type('DitherMethod', headers)                    # 6.4.2
-      have_type('MagickFunction', headers)                  # 6.4.8-8
-      have_type('ImageLayerMethod', headers)                # 6.3.6 replaces MagickLayerMethod
-      have_type('long double', headers)
-      #have_type("unsigned long long", headers)
-      #have_type("uint64_t", headers)
-      #have_type("__int64", headers)
-      #have_type("uintmax_t", headers)
-      #check_sizeof("unsigned long", headers)
-      #check_sizeof("Image *", headers)
-
-      have_enum_values('AlphaChannelType', ['CopyAlphaChannel',                    # 6.4.3-7
-                                            'BackgroundAlphaChannel',              # 6.5.2-5
-                                            'RemoveAlphaChannel'], headers)        # 6.7.5-1
-      have_enum_values('CompositeOperator', ['BlurCompositeOp',                    # 6.5.3-7
-                                             'DistortCompositeOp',                 # 6.5.3-10
-                                             'LinearBurnCompositeOp',              # 6.5.4-3
-                                             'LinearDodgeCompositeOp',             # 6.5.4-3
-                                             'MathematicsCompositeOp',             # 6.5.4-3
-                                             'PegtopLightCompositeOp',             # 6.5.4-3
-                                             'PinLightCompositeOp',                # 6.5.4-3
-                                             'VividLightCompositeOp'], headers)    # 6.5.4-3
-      have_enum_values('CompressionType', ['DXT1Compression',                      # 6.3.9-3
-                                           'DXT3Compression',                      # 6.3.9-3
-                                           'DXT5Compression',                      # 6.3.9-3
-                                           'ZipSCompression',                      # 6.5.5-4
-                                           'PizCompression',                       # 6.5.5-4
-                                           'Pxr24Compression',                     # 6.5.5-4
-                                           'B44Compression',                       # 6.5.5-4
-                                           'B44ACompression'], headers)            # 6.5.5-4
-
-      have_enum_values('DistortImageMethod', ['BarrelDistortion',                  # 6.4.2-5
-                                              'BarrelInverseDistortion',           # 6.4.3-8
-                                              'BilinearForwardDistortion',         # 6.5.1-2
-                                              'BilinearReverseDistortion',         # 6.5.1-2
-                                              'DePolarDistortion',                 # 6.4.2-6
-                                              'PolarDistortion',                   # 6.4.2-6
-                                              'PolynomialDistortion',              # 6.4.2-4
-                                              'ShepardsDistortion'], headers)      # 6.4.2-4
-      have_enum_value('DitherMethod', 'NoDitherMethod', headers)                   # 6.4.3
-      have_enum_values('FilterTypes', ['KaiserFilter',                             # 6.3.6
-                                       'WelshFilter',                              # 6.3.6-4
-                                       'ParzenFilter',                             # 6.3.6-4
-                                       'LagrangeFilter',                           # 6.3.7-2
-                                       'BohmanFilter',                             # 6.3.7-2
-                                       'BartlettFilter',                           # 6.3.7-2
-                                       'SentinelFilter'], headers)                 # 6.3.7-2
-      have_enum_values('MagickEvaluateOperator', ['PowEvaluateOperator',           # 6.4.1-9
-                                                  'LogEvaluateOperator',            # 6.4.2
-                                                  'ThresholdEvaluateOperator',      # 6.4.3
-                                                  'ThresholdBlackEvaluateOperator', # 6.4.3
-                                                  'ThresholdWhiteEvaluateOperator', # 6.4.3
-                                                  'GaussianNoiseEvaluateOperator',  # 6.4.3
-                                                  'ImpulseNoiseEvaluateOperator',   # 6.4.3
-                                                  'LaplacianNoiseEvaluateOperator', # 6.4.3
-                                                  'MultiplicativeNoiseEvaluateOperator', # 6.4.3
-                                                  'PoissonNoiseEvaluateOperator',   # 6.4.3
-                                                  'UniformNoiseEvaluateOperator',   # 6.4.3
-                                                  'CosineEvaluateOperator',         # 6.4.8-5
-                                                  'SineEvaluateOperator',           # 6.4.8-5
-                                                  'AddModulusEvaluateOperator'],    # 6.4.8-5
-                       headers)
-      have_enum_values('MagickFunction', ['ArcsinFunction',                        # 6.5.2-8
-                                          'ArctanFunction',                        # 6.5.2-8
-                                          'PolynomialFunction',                    # 6.4.8-8
-                                          'SinusoidFunction'], headers)            # 6.4.8-8
-      have_enum_values('ImageLayerMethod', ['FlattenLayer',                           # 6.3.6-2
-                                            'MergeLayer',                             # 6.3.6
-                                            'MosaicLayer',                            # 6.3.6-2
-                                            'TrimBoundsLayer' ], headers)             # 6.4.3-8
-      have_enum_values('VirtualPixelMethod', ['HorizontalTileVirtualPixelMethod',     # 6.4.2-6
-                                              'VerticalTileVirtualPixelMethod',       # 6.4.2-6
-                                              'HorizontalTileEdgeVirtualPixelMethod', # 6.5.0-1
-                                              'VerticalTileEdgeVirtualPixelMethod',   # 6.5.0-1
-                                              'CheckerTileVirtualPixelMethod'],       # 6.5.0-1
-                       headers)
-
-      # Now test Ruby 1.9.0 features.
-      headers = ['ruby.h']
-      if have_header('ruby/io.h')
-        headers << 'ruby/io.h'
-      else
-        headers << 'rubyio.h'
+      unless have_header('malloc.h')
+        have_header('malloc/malloc.h')
       end
 
-      have_func('rb_frame_this_func', headers)
-
       # Miscellaneous constants
       $defs.push("-DRUBY_VERSION_STRING=\"ruby #{RUBY_VERSION}\"")
       $defs.push("-DRMAGICK_VERSION_STRING=\"RMagick #{RMAGICK_VERS}\"")
 
+      $defs.push('-DIMAGEMAGICK_GREATER_THAN_EQUAL_6_8_9=1') if im_version_at_least?('6.8.9')
+      $defs.push('-DIMAGEMAGICK_GREATER_THAN_EQUAL_6_9_0=1') if im_version_at_least?('6.9.0')
+      $defs.push('-DIMAGEMAGICK_7=1') if im_version_at_least?('7.0.0')
+
       create_header
     end
 
@@ -526,12 +366,24 @@ SRC
       print_summary
     end
 
-    def print_summary
-      summary = <<"END_SUMMARY"
+    def magick_command
+      @magick_command ||= if find_executable('magick')
+                            'magick'
+                          elsif find_executable('identify')
+                            'identify'
+                          else
+                            raise NotImplementedError, "no executable found for ImageMagick"
+                          end
+    end
 
+    def im_version_at_least?(version)
+      Gem::Version.new($magick_version) >= Gem::Version.new(version)
+    end
 
+    def print_summary
+      summary = <<"END_SUMMARY"
 #{'=' * 70}
-#{DateTime.now.strftime('%a %d%b%y %T')}
+#{Time.now.strftime('%a %d %b %y %T')}
 This installation of RMagick #{RMAGICK_VERS} is configured for
 Ruby #{RUBY_VERSION} (#{RUBY_PLATFORM}) and ImageMagick #{$magick_version}
 #{'=' * 70}
@@ -549,6 +401,6 @@ extconf = RMagick::Extconf.new
 at_exit do
   msg = "Configured compile options: #{extconf.configured_compile_options}"
   Logging.message msg
-  message msg+"\n"
+  message msg + "\n"
 end
 extconf.create_makefile_file
