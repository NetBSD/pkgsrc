$NetBSD: patch-bam.lua,v 1.1 2015/09/12 18:53:17 wiz Exp $

=============================================================================
This patch hardwires python to python2.7 (which we depend on in the Makefile)

I doubt upstream would want or need it.
=============================================================================


--- bam.lua.orig	2015-09-12 06:04:33.000000000 +0200
+++ bam.lua	2015-09-12 06:04:26.000000000 +0200
@@ -20,7 +20,7 @@
 	if family == "windows" then
 		return str_replace(name, "/", "\\")
 	end
-	return "python " .. name
+	return "python2.7 " .. name
 end
 
 function CHash(output, ...)
