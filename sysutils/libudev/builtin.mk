# $NetBSD: builtin.mk,v 1.3 2025/05/04 09:57:54 vins Exp $

BUILTIN_PKG:=			libudev
PKGCONFIG_BASE.libudev=		/usr
PKGCONFIG_FILE.libudev=		${PKGCONFIG_BASE.libudev}/lib/pkgconfig/libudev.pc
PKGCONFIG_FILE.libudev+=	${PKGCONFIG_BASE.libudev}/lib${LIBABISUFFIX}/pkgconfig/libudev.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

CHECK_BUILTIN.libudev?=	no
.if ${CHECK_BUILTIN.libudev:tl} == no

.  if ${USE_BUILTIN.libudev:tl} == yes
BUILDLINK_PREFIX.libudev=	/usr
BUILDLINK_FILES.libudev+=	lib/pkgconfig/libudev.pc
BUILDLINK_FILES.libudev+=	lib${LIBABISUFFIX}/pkgconfig/libudev.pc
.  endif

.endif  # CHECK_BUILTIN.libudev
