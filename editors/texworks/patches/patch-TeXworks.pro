$NetBSD: patch-TeXworks.pro,v 1.1.1.1 2012/03/21 22:44:20 markd Exp $

pkg-config doesnt know about zlib so just assume its there

--- TeXworks.pro.orig	2011-06-29 17:03:14.000000000 +0000
+++ TeXworks.pro
@@ -103,7 +103,7 @@ unix:!macx { # on Unix-ish platforms we 
 	CONFIG		+= link_pkgconfig
 	PKGCONFIG	+= hunspell
 	PKGCONFIG	+= poppler-qt4
-	PKGCONFIG	+= zlib
+	#PKGCONFIG	+= zlib
 
 	# Enclose the path in \\\" (which later gets expanded to \", which in turn
 	# gets expanded to " in the c++ code)
