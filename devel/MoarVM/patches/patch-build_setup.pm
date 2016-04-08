$NetBSD: patch-build_setup.pm,v 1.1 2016/04/08 20:26:46 bsiegert Exp $

pkgsrc uses gmake everywhere, so use gmake syntax.
Not for upstreaming.

--- build/setup.pm.orig	2015-12-25 12:37:32.000000000 +0000
+++ build/setup.pm
@@ -171,12 +171,12 @@ our %TC_BSD = (
     %TC_POSIX,
 
     mknoisy => <<'TERM',
-.if $(NOISY) != 1
+ifneq ($(NOISY), 1)
 MSG = @echo
 CMD = @
 NOOUT = > @nul@
 NOERR = 2> @nul@
-.endif
+endif
 TERM
 );
 
