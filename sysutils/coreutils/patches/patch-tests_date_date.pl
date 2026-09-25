$NetBSD: patch-tests_date_date.pl,v 1.2 2026/09/25 07:14:32 wiz Exp $

https://debbugs.gnu.org/cgi/bugreport.cgi?bug=81923

--- tests/date/date.pl.orig	2026-09-01 21:37:43.000000000 +0000
+++ tests/date/date.pl
@@ -173,9 +173,9 @@ my @Tests =
 
      # test for RFC-822 conformance
      ['rfc822-1', "-R -d '$d1'", {OUT=>"Sun, 19 Jan 1997 08:17:48 +0000"},
-      # Solaris 5.9's /bin/sh emits this diagnostic to stderr
-      # if you don't have support for the named locale.
-      {ERR_SUBST => q!s/^couldn't set locale correctly\n//!},
+      # Solaris 5.9's /bin/sh can emit "couldn't set locale"
+      # NetBSD 12 sh can emit "setlocale failed"
+      {ERR_SUBST => q!s/.*(?:couldn't set locale|failed setlocale).*\n//!},
       {ENV => 'LC_ALL=de_DE TZ=UTC0'}],
 
      # Relative seconds, with time.  fixed in 2.0j
