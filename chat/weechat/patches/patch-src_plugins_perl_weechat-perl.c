$NetBSD: patch-src_plugins_perl_weechat-perl.c,v 1.1 2019/07/31 10:33:08 nia Exp $

Apply this workaround to NetBSD too, it seems to have the same problem
with segfaulting on exit if the perl plugin is loaded.

--- src/plugins/perl/weechat-perl.c.orig	2019-06-06 18:43:20.000000000 +0000
+++ src/plugins/perl/weechat-perl.c
@@ -1340,7 +1340,7 @@ weechat_plugin_end (struct t_weechat_plu
     }
 #endif /* MULTIPLICITY */
 
-#if defined(PERL_SYS_TERM) && !defined(__FreeBSD__) && !defined(WIN32) && !defined(__CYGWIN__) && !(defined(__APPLE__) && defined(__MACH__))
+#if defined(PERL_SYS_TERM) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(WIN32) && !defined(__CYGWIN__) && !(defined(__APPLE__) && defined(__MACH__))
     /*
      * we call this function on all OS, but NOT on FreeBSD or Cygwin,
      * because it crashes with no reason (bug in Perl?)
