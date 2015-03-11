$NetBSD: patch-config.mk,v 1.1 2015/03/11 23:19:58 tnn Exp $

Honour PKGMANDIR

--- config.mk.orig	2015-03-11 23:13:16.000000000 +0000
+++ config.mk
@@ -548,7 +548,7 @@ RESULTDIR_DEFAULT = /tmp/netpbm-test
 
 # Subdirectory of the package directory ($(pkgdir)) in which man pages
 # go.
-PKGMANDIR = man
+PKGMANDIR? = man
 
 # File permissions for installed files.
 # Note that on some systems (e.g. Solaris), 'install' can't use the 
