$NetBSD: patch-src_lib_Sympa_Session.pm,v 1.1 2015/09/26 14:56:10 bouyer Exp $
Fix perl 5.22 waring (which is fatal here)

--- ./src/lib/Sympa/Session.pm.orig	2015-09-25 23:38:08.000000000 +0200
+++ ./src/lib/Sympa/Session.pm	2015-09-25 23:39:03.000000000 +0200
@@ -132,7 +132,7 @@
     my $sdm = Sympa::DatabaseManager->instance;
 
     ## Load existing session.
-    if ($cookie and $cookie =~ /^\d{,16}$/) {
+    if ($cookie and $cookie =~ /^\d{16}$/) {
         ## Compatibility: session by older releases of Sympa.
         $id_session     = $cookie;
         $is_old_session = 1;
