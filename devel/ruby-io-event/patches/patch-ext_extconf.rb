$NetBSD: patch-ext_extconf.rb,v 1.1 2022/11/11 13:37:40 taca Exp $

Check existence of EV_UDATA_SPECIFIC.

--- ext/extconf.rb.orig	2022-11-04 16:36:30.481849167 +0000
+++ ext/extconf.rb
@@ -49,7 +49,9 @@ if have_header('sys/epoll.h')
 end
 
 if have_header('sys/event.h')
-	$srcs << "io/event/selector/kqueue.c"
+  if have_macro('EV_UDATA_SPECIFIC', 'sys/event.h')
+    $srcs << "io/event/selector/kqueue.c"
+  end
 end
 
 have_header('sys/eventfd.h')
