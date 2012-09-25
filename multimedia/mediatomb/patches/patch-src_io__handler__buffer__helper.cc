$NetBSD: patch-src_io__handler__buffer__helper.cc,v 1.1 2012/09/25 11:45:11 ryoon Exp $

Add SONY Bravia support
http://blog-imgs-30.fc2.com/h/o/r/horip/mediatomb-0_12_1_bravia_support_0_1_patch.txt

--- src/io_handler_buffer_helper.cc.orig	2010-03-25 14:58:11.000000000 +0000
+++ src/io_handler_buffer_helper.cc
@@ -222,6 +222,7 @@ void IOHandlerBufferHelper::stopBufferTh
 void *IOHandlerBufferHelper::staticThreadProc(void *arg)
 {
     log_debug("starting buffer thread... thread: %d\n", pthread_self());
+    log_debug("arg for staticThreadProc: %s\n", arg);
     IOHandlerBufferHelper *inst = (IOHandlerBufferHelper *)arg;
     inst->threadProc();
     log_debug("buffer thread shut down. thread: %d\n", pthread_self());
