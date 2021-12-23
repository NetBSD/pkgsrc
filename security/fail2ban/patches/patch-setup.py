$NetBSD: patch-setup.py,v 1.1 2021/12/23 22:27:35 wiz Exp $

Compatibility with latest setuptools.

--- setup.py.orig	2021-12-23 22:23:32.219701295 +0000
+++ setup.py
@@ -186,7 +186,6 @@ commands.'''
 if setuptools:
 	setup_extra = {
 		'test_suite': "fail2ban.tests.utils.gatherTests",
-		'use_2to3': True,
 	}
 else:
 	setup_extra = {}
