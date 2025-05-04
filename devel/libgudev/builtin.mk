# $NetBSD: builtin.mk,v 1.1 2025/05/04 10:11:28 vins Exp $

BUILTIN_PKG:=			libgudev
PKGCONFIG_BASE.libgudev=	/usr
PKGCONFIG_FILE.libgudev=	${PKGCONFIG_BASE.libgudev}/lib/pkgconfig/gudev-1.0.pc
PKGCONFIG_FILE.libgudev+=	${PKGCONFIG_BASE.libgudev}/lib${LIBABISUFFIX}/pkgconfig/gudev-1.0.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

CHECK_BUILTIN.libgudev?=	no
.if ${CHECK_BUILTIN.libgudev:tl} == no

.  if ${USE_BUILTIN.libgudev:tl} == yes
BUILDLINK_PREFIX.libgudev=	/usr
BUILDLINK_FILES.libgudev+=	lib/pkgconfig/gudev-1.0.pc
BUILDLINK_FILES.libgudev+=	lib${LIBABISUFFIX}/pkgconfig/gudev-1.0.pc
.  endif

.endif  # CHECK_BUILTIN.libgudev
