$NetBSD: patch-install.sh,v 1.2 2026/10/31 22:33:34 hauke Exp $

Do not build the LaTeX based documentation here.

--- install.sh.orig	2026-10-31 22:10:57.695721177 +0000
+++ install.sh
@@ -26,11 +26,8 @@ if [ "$4" != "" ]; then
 else
   LIBPATH=
 fi
-if [ "$5" != "" ]; then
-  DOCPATH=${INSTROOT}$5
-else
-  DOCPATH=
-fi
+
+DOCPATH=
 
 # this is not a perfect solution, but I don't know a better one at the moment:
 
