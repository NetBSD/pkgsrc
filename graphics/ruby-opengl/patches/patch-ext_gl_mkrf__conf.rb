$NetBSD: patch-ext_gl_mkrf__conf.rb,v 1.1 2016/05/26 17:08:57 taca Exp $

Make sure to set rpath.

--- ext/gl/mkrf_conf.rb.orig	2016-05-26 07:39:33.064606316 +0000
+++ ext/gl/mkrf_conf.rb
@@ -24,11 +24,13 @@ Mkrf::Generator.new( 'gl' ) do |g|
 	when /darwin/
 		g.cflags << RUBYVER
 		g.ldshared << ' -framework OpenGL'
+		g.ldshared << " #{ENV['LDSHARED']}"
 	when /mswin32/
 		g.cflags << ' -DWIN32' + RUBYVER
 		g.include_library( 'opengl32.lib', 'glVertex3d')
 	else
 		g.cflags << ' -Wall' + RUBYVER
 		g.include_library( 'GL', 'glVertex3d')
+		g.ldshared << " #{ENV['LDSHARED']}"
 	end
 end
