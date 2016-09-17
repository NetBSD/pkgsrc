# $NetBSD: builtin.mk,v 1.4 2016/09/17 05:20:34 richard Exp $

BUILTIN_PKG:=	fuse
PKGCONFIG_BASE.fuse=	/usr
PKGCONFIG_FILE.fuse=	/usr/lib/pkgconfig/fuse.pc
PKGCONFIG_FILE.fuse+=	/usr/lib${LIBABISUFFIX}/pkgconfig/fuse.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

.if !empty(USE_BUILTIN.fuse:M[yY][eE][sS])
BUILDLINK_FILES.fuse+=	lib/pkgconfig/fuse.pc
BUILDLINK_FILES.fuse+=	lib${LIBABISUFFIX}/pkgconfig/fuse.pc
.endif
