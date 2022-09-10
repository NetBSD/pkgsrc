$NetBSD: patch-tools_extract-vector-icon.sh,v 1.1 2022/09/10 09:24:48 wiz Exp $

Fix unportable test(1) operator.
https://gitlab.gnome.org/GNOME/gimp/-/issues/8605

--- tools/extract-vector-icon.sh.orig	2022-08-21 19:21:38.000000000 +0000
+++ tools/extract-vector-icon.sh
@@ -35,7 +35,7 @@ fi
 compute_viewbox="$(pwd)/../../tools/compute-svg-viewbox"
 source="$1"
 id="$2"
-if [ "$#" == 4 ]; then
+if [ "$#" = 4 ]; then
   # The expected display width/height for the image.
   width="$3"
   height="$4"
@@ -107,7 +107,7 @@ rm -f $svg_temp
 
 # The finale SVG file with properly set viewBox.
 svg="$svg_start  $viewBox"
-if [ "$#" == 5 ]; then
+if [ "$#" = 5 ]; then
   svg="$svg
   width=\"$width\"
   height=\"$height\""
