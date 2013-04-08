# $NetBSD: builtin.mk,v 1.2 2013/04/08 11:17:13 rodent Exp $

BUILTIN_PKG:=	fuse
PKGCONFIG_BASE.fuse=	/usr
PKGCONFIG_FILE.fuse=	/usr/lib/pkgconfig/fuse.pc
.include "../../mk/buildlink3/pkgconfig-builtin.mk"

.if !empty(USE_BUILTIN.fuse:M[yY][eE][sS])
BUILDLINK_FILES.fuse+=	lib/pkgconfig/fuse.pc
.endif
