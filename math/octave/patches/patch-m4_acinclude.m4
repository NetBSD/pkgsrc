$NetBSD: patch-m4_acinclude.m4,v 1.1 2016/09/28 02:54:15 maya Exp $

we pass and assume a given MACHINE_GNU_PLATFORM, but this package did not
use this value due to an error.
the guess it had for linux (x86_64-unknown-linux-gnu), seems to trample
over our own tools:
https://mail-index.netbsd.org/pkgsrc-users/2014/03/26/msg019464.html

--- m4/acinclude.m4.orig	2016-04-20 18:23:56.000000000 +0000
+++ m4/acinclude.m4
@@ -1651,7 +1651,7 @@ AC_DEFUN([OCTAVE_CANONICAL_HOST], [
     host=unknown-unknown-unknown
     AC_MSG_WARN([configuring Octave for unknown system type])
   fi
-  canonical_host_type=$host
+  canonical_host_type=$host_alias
   AC_SUBST(canonical_host_type)
   if test -z "$host_cpu"; then
     host_cpu=unknown
