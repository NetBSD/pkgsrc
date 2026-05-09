# $NetBSD: builtin.mk,v 1.1 2026/05/09 20:01:32 vins Exp $

BUILTIN_PKG:=		fuse
PKGCONFIG_BASE.fuse=	/usr
PKGCONFIG_FILE.fuse=	/usr/lib/pkgconfig/fuse3.pc
PKGCONFIG_FILE.fuse+=	/usr/lib${LIBABISUFFIX}/pkgconfig/fuse3.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

.if ${USE_BUILTIN.fuse:tl} == yes
BUILDLINK_FILES.fuse+=	lib/pkgconfig/fuse3.pc
BUILDLINK_FILES.fuse+=	lib${LIBABISUFFIX}/pkgconfig/fuse3.pc
.endif
