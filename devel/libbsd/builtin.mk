# $NetBSD: builtin.mk,v 1.4 2025/09/28 06:18:35 vins Exp $

BUILTIN_PKG:=		libbsd
PKGCONFIG_BASE.libbsd=	/usr
PKGCONFIG_FILE.libbsd=	${PKGCONFIG_BASE.libbsd}/lib/pkgconfig/libbsd.pc
PKGCONFIG_FILE.libbsd+=	${PKGCONFIG_BASE.libbsd}/lib${LIBABISUFFIX}/pkgconfig/libbsd.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

CHECK_BUILTIN.libbsd?=	no
.if ${CHECK_BUILTIN.libbsd:tl} == no

.  if ${USE_BUILTIN.libbsd:tl} == yes
BUILDLINK_PREFIX.libbsd=	/usr
BUILDLINK_FILES.libbsd+=	lib/pkgconfig/libbsd.pc
BUILDLINK_FILES.libbsd+=	lib${LIBABISUFFIX}/pkgconfig/libbsd.pc
.  endif

.endif  # CHECK_BUILTIN.libbsd
