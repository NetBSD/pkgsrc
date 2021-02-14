$NetBSD: patch-module_configuration_ruby_milter-manager-ruby-configuration.c,v 1.1 2021/02/14 15:33:02 taca Exp $

Don't use RETSIGTYPE but simply void.

--- module/configuration/ruby/milter-manager-ruby-configuration.c.orig	2019-09-09 09:17:06.177788299 +0000
+++ module/configuration/ruby/milter-manager-ruby-configuration.c
@@ -166,18 +166,18 @@ milter_manager_ruby_configuration_regist
 static void
 ruby_init_without_signal_change (void)
 {
-    RETSIGTYPE (*sigint_handler)_((int));
+    void (*sigint_handler)_((int));
 #ifdef SIGHUP
-    RETSIGTYPE (*sighup_handler)_((int));
+    void (*sighup_handler)_((int));
 #endif
 #ifdef SIGQUIT
-    RETSIGTYPE (*sigquit_handler)_((int));
+    void (*sigquit_handler)_((int));
 #endif
 #ifdef SIGTERM
-    RETSIGTYPE (*sigterm_handler)_((int));
+    void (*sigterm_handler)_((int));
 #endif
 #ifdef SIGSEGV
-    RETSIGTYPE (*sigsegv_handler)_((int));
+    void (*sigsegv_handler)_((int));
 #endif
 
     sigint_handler = signal(SIGINT, SIG_DFL);
@@ -386,7 +386,7 @@ MILTER_MANAGER_MODULE_IMPL_INIT (GTypeMo
 static void
 ruby_cleanup_without_signal_change (int exit_code)
 {
-    RETSIGTYPE (*sigint_handler)_((int));
+    void (*sigint_handler)_((int));
 #ifdef HAVE_RB_THREAD_RESET_TIMER_THREAD
     const gchar *milter_manager_ruby_reset_timer_thread_before_cleanup = NULL;
 #endif
