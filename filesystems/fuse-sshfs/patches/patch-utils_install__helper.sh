$NetBSD: patch-utils_install__helper.sh,v 1.1 2021/12/02 07:28:40 pho Exp $

`ln --relative' is a Linux-only thing. Do not use it. There should be
no reason we can't just use hard links here.

--- utils/install_helper.sh.orig	2021-06-08 08:52:08.000000000 +0000
+++ utils/install_helper.sh
@@ -12,8 +12,8 @@ prefix="${MESON_INSTALL_DESTDIR_PREFIX}"
 
 mkdir -p "${prefix}/${sbindir}"
 
-ln -svf --relative "${prefix}/${bindir}/sshfs" \
+ln -vf "${prefix}/${bindir}/sshfs" \
    "${prefix}/${sbindir}/mount.sshfs"
 
-ln -svf --relative "${prefix}/${bindir}/sshfs" \
+ln -vf "${prefix}/${bindir}/sshfs" \
    "${prefix}/${sbindir}/mount.fuse.sshfs"
