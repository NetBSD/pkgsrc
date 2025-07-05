$NetBSD: patch-install.sh,v 1.1 2025/07/05 12:12:14 hauke Exp $

We only build documentation here.

--- install.sh.orig	2025-07-05 11:09:22.500068974 +0000
+++ install.sh
@@ -6,10 +6,10 @@
 if [ "${INSTROOT}" != "" ]; then
   INSTROOT=${INSTROOT}/
 fi
-BINPATH=${INSTROOT}$1
-INCPATH=${INSTROOT}$2
-MANPATH=${INSTROOT}$3
-LIBPATH=${INSTROOT}$4
+#BINPATH=${INSTROOT}$1
+#INCPATH=${INSTROOT}$2
+#MANPATH=${INSTROOT}$3
+#LIBPATH=${INSTROOT}$4
 DOCPATH=${INSTROOT}$5
 
 # this is not a perfect solution, but I don't know a better one at the moment:
