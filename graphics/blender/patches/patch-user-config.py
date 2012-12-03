$NetBSD: patch-user-config.py,v 1.1 2012/12/03 13:15:52 ryoon Exp $

From Gentoo's ebuild

--- user-config.py.orig	2012-12-03 06:03:04.000000000 +0000
+++ user-config.py
@@ -0,0 +1,2 @@
+LINKFLAGS=[@MYLDFLAGS@]
+PLATFORM_LINKFLAGS=[@MYLDFLAGS@]
