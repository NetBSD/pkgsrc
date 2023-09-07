# $NetBSD: builtin.mk,v 1.6 2023/09/07 19:38:14 vins Exp $

BUILTIN_PKG:=		fuse
PKGCONFIG_BASE.fuse=	/usr
PKGCONFIG_FILE.fuse=	/usr/lib/pkgconfig/fuse.pc
PKGCONFIG_FILE.fuse+=	/usr/lib${LIBABISUFFIX}/pkgconfig/fuse.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

.if ${USE_BUILTIN.fuse:tl} == yes
BUILDLINK_FILES.fuse+=	lib/pkgconfig/fuse.pc
BUILDLINK_FILES.fuse+=	lib${LIBABISUFFIX}/pkgconfig/fuse.pc
.endif
