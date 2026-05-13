# $NetBSD: hacks.mk,v 1.2 2026/05/13 18:48:28 vins Exp $

.if !defined(GVFS_HACKS_MK)
GVFS_HACKS_MK=	defined

### [Sat Nov 15 02:58:22 JST 2025 : pho]
### gvfs' meson.build files uses install_rpath to embed rpath to
### ${PREFIX}/lib/gvfs. Unpatched Meson handles this just fine but
### alas... our Meson has a patch to kill the rpath fixup
### (patches/patch-mesonbuild_scripts_depfixer.py) and it renders
### install_rpath non-functioning. We can't simply get away with deleting
### the patch, because depfixer.py cannot inject a DT_RPATH that is longer
### than existing ones. (Have they considered using patchelf instead of
### hand-rolling their own ELF patcher?) To overcome the limitation they
### introduced on their own, Meson allocates a dummy rpath with the same
### length of install_rpath with every character replaced with 'X', like
### "-Wl,-rpath,XXXXXXXXXX", which doesn't begin with a '/' so our
### cwrappers remove it! Meson and our cwrappers fight against each other
### in a very indirect way, and the only way around is to do this silly
### hack:
PKG_HACKS+=	rpath-fixup
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/gvfs

### [Wed May 13 18:43 UTC 2026 : vins]
### Disable meson's default of using "-Wl,--as-needed" on ld.bfd arches,
### to prevent build failures due to undefined references.
MESON_ARGS+=	-Db_asneeded=false

.endif # GVFS_HACKS_MK
