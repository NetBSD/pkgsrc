$NetBSD: patch-scripts_utils.sh,v 1.1 2020/01/11 13:37:15 nia Exp $

Resolve portability issues.

--- scripts/utils.sh.orig	2017-10-14 13:23:55.000000000 +0000
+++ scripts/utils.sh
@@ -12,8 +12,8 @@ do_install() {
 
 	cp index.theme "${INSTALL_DIR}"
 
-	cp -rt "${INSTALL_DIR}" \
-			assets gtk-2.0 metacity-1 openbox-3 xfce-notify-4.0 xfwm4 unity
+	cp -r \
+			assets gtk-2.0 metacity-1 openbox-3 xfce-notify-4.0 xfwm4 unity "${INSTALL_DIR}"
 
 	for _DIR in "${GTKDIR}" "${GTK320DIR}"
 	do
@@ -21,14 +21,15 @@ do_install() {
 
 		mkdir -p "${_DIR}"
 
-		cp -t "${_DIR}" \
+		cp \
 			"${GTKVER}/gtk.css" \
 			"${GTKVER}/gtk-dark.css" \
 			"${GTKVER}/gtk.gresource" \
-			"${GTKVER}/thumbnail.png"
+			"${GTKVER}/thumbnail.png" \
+			"${_DIR}"
 
 		cd "${_DIR}"
-		ln -srf ../assets assets
+		ln -sf ../assets assets
 		cd -
 	done
 }
