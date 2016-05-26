$NetBSD: patch-ext_glut_mkrf__conf.rb,v 1.1 2016/05/26 17:08:57 taca Exp $

Make sure to set rpath.

--- ext/glut/mkrf_conf.rb.orig	2016-05-26 08:03:52.577469373 +0000
+++ ext/glut/mkrf_conf.rb
@@ -23,6 +23,7 @@ Mkrf::Generator.new( 'glut' ) do |g|
 	when /darwin/
 		g.cflags << RUBYVER
 		g.ldshared << ' -framework GLUT -framework OpenGL -framework Cocoa'
+		g.ldshared << " #{ENV['LDSHARED']}"
 	when /mswin32/
 		g.cflags << ' -DWIN32' + RUBYVER
 		g.include_library( 'glut32.lib', 'glutSolidTeapot' )
@@ -33,5 +34,6 @@ Mkrf::Generator.new( 'glut' ) do |g|
 		g.include_library( 'glut', 'glutSolidTeapot' )
 		g.include_library( 'GLU', 'gluLookAt' )
 		g.include_library( 'GL', 'glVertex3d')
+		g.ldshared << " #{ENV['LDSHARED']}"
 	end
 end
