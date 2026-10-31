$NetBSD: patch-install.sh,v 1.2 2026/10/31 22:33:34 hauke Exp $

We only build documentation here.

--- install.sh.orig	2026-10-31 22:26:14.593442281 +0000
+++ install.sh
@@ -3,34 +3,8 @@
 
 # assure we don't copy to absolute paths / root dir if $INSTROOT is not set:
 
-if [ "${INSTROOT}" != "" ]; then
-  INSTROOT=${INSTROOT}/
-fi
-if [ "$1" != "" ]; then
-  BINPATH=${INSTROOT}$1
-else
-  BINPATH=
-fi
-if [ "$2" != "" ]; then
-  INCPATH=${INSTROOT}$2
-else
-  INCPATH=
-fi
-if [ "$3" != "" ]; then
-  MANPATH=${INSTROOT}$3
-else
-  MANPATH=
-fi
-if [ "$4" != "" ]; then
-  LIBPATH=${INSTROOT}$4
-else
-  LIBPATH=
-fi
-if [ "$5" != "" ]; then
-  DOCPATH=${INSTROOT}$5
-else
-  DOCPATH=
-fi
+DOCPATH=${INSTROOT}$5
+
 
 # this is not a perfect solution, but I don't know a better one at the moment:
 
