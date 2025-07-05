$NetBSD: patch-install.sh,v 1.1 2025/07/05 12:12:14 hauke Exp $

Do not build the LaTeX based documentation here.

--- install.sh.orig	2025-07-05 10:57:38.333481142 +0000
+++ install.sh
@@ -10,7 +10,7 @@ BINPATH=${INSTROOT}$1
 INCPATH=${INSTROOT}$2
 MANPATH=${INSTROOT}$3
 LIBPATH=${INSTROOT}$4
-DOCPATH=${INSTROOT}$5
+#DOCPATH=${INSTROOT}$5
 
 # this is not a perfect solution, but I don't know a better one at the moment:
 
