$NetBSD: patch-ext_glu_mkrf__conf.rb,v 1.1 2016/05/26 17:08:57 taca Exp $

Make sure to set rpath.

--- ext/glu/mkrf_conf.rb.orig	2016-05-26 08:03:52.613279441 +0000
+++ ext/glu/mkrf_conf.rb
@@ -23,6 +23,7 @@ Mkrf::Generator.new( 'glu' ) do |g|
 	when /darwin/
 		g.cflags << RUBYVER
 		g.ldshared << ' -framework OpenGL'
+		g.ldshared << " #{ENV['LDSHARED']}"
 	when /mswin32/
 		g.cflags << ' -DWIN32' + RUBYVER
 		g.include_library( 'opengl32.lib', 'glVertex3d')
@@ -31,5 +32,6 @@ Mkrf::Generator.new( 'glu' ) do |g|
 		g.cflags << ' -Wall' + RUBYVER
 		g.include_library( 'GLU', 'gluLookAt' )
 		g.include_library( 'GL', 'glVertex3d')
+		g.ldshared << " #{ENV['LDSHARED']}"
 	end
 end
