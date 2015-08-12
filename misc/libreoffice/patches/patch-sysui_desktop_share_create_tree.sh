$NetBSD: patch-sysui_desktop_share_create_tree.sh,v 1.1 2015/08/12 00:57:20 ryoon Exp $

--- sysui/desktop/share/create_tree.sh.orig	2015-02-20 17:33:24.000000000 +0000
+++ sysui/desktop/share/create_tree.sh
@@ -63,7 +63,7 @@ test -n "${OFFICE_PREFIX}" && office_pre
 office_root=${office_prefix}/${PREFIX}
 
 #this symlink is needed to have the API boostrap functions running right
-ln -sf "${office_root}/program/soffice" "${DESTDIR}/${PREFIXDIR}/bin/${PREFIX}"
+ln -sf "${INSTALLDIR}/program/soffice" "${DESTDIR}/${PREFIXDIR}/bin/${PREFIX}"
 
 if test "${PREFIX}" != libreoffice${PRODUCTVERSION} -a "${PREFIX}" != libreofficedev${PRODUCTVERSION}  ; then
     # compat symlinks
@@ -79,7 +79,7 @@ chmod 0644 "${DESTDIR}/${PREFIXDIR}/shar
 
 mkdir -p "${DESTDIR}/${PREFIXDIR}/share/applications"
 for i in `cat launcherlist`; do
-  ln -sf "${office_root}/share/xdg/${i}" "${DESTDIR}/${PREFIXDIR}/share/applications/${PREFIX}-${i}"
+  ln -sf "${INSTALLDIR}/share/xdg/${i}" "${DESTDIR}/${PREFIXDIR}/share/applications/${PREFIX}-${i}"
 done
 
 mkdir -p "${DESTDIR}/${PREFIXDIR}/share/appdata"
