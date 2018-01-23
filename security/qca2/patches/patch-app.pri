$NetBSD: patch-app.pri,v 1.1 2018/01/23 12:57:05 jperkin Exp $

Don't override QMAKE_MACOSX_DEPLOYMENT_TARGET.

--- app.pri.orig	2009-04-24 21:12:15.000000000 +0000
+++ app.pri
@@ -1,7 +1,5 @@
 include(confapp.pri)
 
-mac:QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.3
-
 exists(crypto.prf) {
 	# our apps should build against the qca in this tree
 	include(crypto.prf)
