$NetBSD: patch-util_install__helper.sh,v 1.1 2026/05/09 20:00:28 vins Exp $

Keep only the required bits from the install script.

--- util/install_helper.sh.orig	2026-03-18 21:18:34.000000000 +0000
+++ util/install_helper.sh
@@ -24,19 +24,6 @@ else
     DESTDIR="${DESTDIR%/}"
 fi
 
-install -D -m 644 "${MESON_SOURCE_ROOT}/util/fuse.conf" \
-	"${DESTDIR}${sysconfdir}/fuse.conf"
-
-if $useroot; then
-    chown root:root "${DESTDIR}${bindir}/fusermount3"
-    chmod u+s "${DESTDIR}${bindir}/fusermount3"
-
-    if test ! -e "${DESTDIR}/dev/fuse"; then
-        mkdir -p "${DESTDIR}/dev"
-        mknod "${DESTDIR}/dev/fuse" -m 0666 c 10 229
-    fi
-fi
-
 if [ "${udevrulesdir}" != "" ]; then
     install -D -m 644 "${MESON_SOURCE_ROOT}/util/udev.rules" \
         "${DESTDIR}${udevrulesdir}/99-fuse3.rules"
@@ -44,12 +31,5 @@ fi
 
 if [ "$initscriptdir" != "" ]; then
     install -D -m 755 "${MESON_SOURCE_ROOT}/util/init_script" \
-            "${DESTDIR}${initscriptdir}/fuse3"
-
-    if test -x /usr/sbin/update-rc.d && test -z "${DESTDIR}"; then
-        /usr/sbin/update-rc.d fuse3 start 34 S . start 41 0 6 . || /bin/true
-    else
-        echo "== FURTHER ACTION REQUIRED =="
-        echo "Make sure that your init system will start the ${DESTDIR}${initscriptdir}/init.d/fuse3 init script"
-    fi
+            "${DESTDIR}${initscriptdir}/init.d.fuse3"
 fi
