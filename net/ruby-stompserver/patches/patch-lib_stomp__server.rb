$NetBSD: patch-lib_stomp__server.rb,v 1.2 2012/08/13 18:43:34 imil Exp $

Buggy code made pid relative to logdir

--- lib/stomp_server.rb.orig	2012-08-13 12:57:02.000000000 +0000
+++ lib/stomp_server.rb
@@ -67,7 +67,7 @@ module StompServer
       opts[:storage] = File.join(opts[:working_dir],opts[:storage])
       opts[:logdir] = File.join(opts[:working_dir],opts[:logdir])
       opts[:logfile] = File.join(opts[:logdir],opts[:logfile])
-      opts[:pidfile] = File.join(opts[:logdir],opts[:pidfile])
+      opts[:pidfile] = File.join(opts[:working_dir],opts[:pidfile])
       if opts[:auth]
         opts[:passwd] = File.join(opts[:etcdir],'.passwd')
       end
