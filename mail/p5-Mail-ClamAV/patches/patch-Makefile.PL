$NetBSD: patch-Makefile.PL,v 1.1 2011/12/17 16:16:37 marino Exp $

--- Makefile.PL.orig	2011-12-17 13:55:30.949471000 +0000
+++ Makefile.PL
@@ -29,6 +29,7 @@ my %supported_OS = (
     cygwin => 'cygwin',
     linux => 'linux',
     solaris => 'solaris',
+    dragonfly => 'dragonfly',
     freebsd => 'freebsd',
     openbsd => 'openbsd',
     macos => 'MacOS',
