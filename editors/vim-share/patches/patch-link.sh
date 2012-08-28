$NetBSD: patch-link.sh,v 1.1 2012/08/28 05:59:39 morr Exp $

--- src/link.sh.orig	2012-05-25 09:25:48.000000000 +0000
+++ src/link.sh
@@ -53,7 +53,7 @@ else
   if sh link.cmd; then
     touch auto/link.sed
     cp link.cmd linkit.sh
-    for libname in SM ICE nsl dnet dnet_stub inet socket dir elf iconv Xt Xmu Xp Xpm X11 Xdmcp x w perl dl pthread thread readline m crypt attr; do
+    for libname in SM ICE nsl dnet dnet_stub inet socket dir elf Xt Xmu Xp Xpm X11 Xdmcp x w perl dl pthread thread readline m crypt attr; do
       cont=yes
       while test -n "$cont"; do
         if grep "l$libname " linkit.sh >/dev/null; then
