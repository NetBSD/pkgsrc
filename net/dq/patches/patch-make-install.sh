$NetBSD: patch-make-install.sh,v 1.1 2022/01/27 15:31:09 schmonz Exp $

DESTDIR support.

--- make-install.sh.orig	2021-12-28 17:36:08.000000000 +0000
+++ make-install.sh
@@ -28,7 +28,6 @@ do
   mkdir -p "$1/${confbin}" || exit 111
   cp "${bin}/${x}" "$1/${confbin}" || exit 111
   chmod 755 "$1/${confbin}/${x}" || exit 111
-  chown 0:0 "$1/${confbin}/${x}" || exit 111
 done
 echo "=== `date` === finishing"
 
