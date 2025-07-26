# $NetBSD: builtin.mk,v 1.1 2025/07/26 09:06:46 vins Exp $

BUILTIN_PKG:=			imsg-compat
PKGCONFIG_BASE.imsg-compat=	/usr
PKGCONFIG_FILE.imsg-compat=	${PKGCONFIG_BASE.imsg-compat}/lib/pkgconfig/libimsg.pc
PKGCONFIG_FILE.imsg-compat+=	${PKGCONFIG_BASE.imsg-compat}/lib${LIBABISUFFIX}/pkgconfig/libimsg.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

CHECK_BUILTIN.imsg-compat?=	no
.if ${CHECK_BUILTIN.imsg-compat:tl} == no

.  if ${USE_BUILTIN.imsg-compat:tl} == yes
BUILDLINK_PREFIX.imsg-compat=	/usr
BUILDLINK_FILES.imsg-compat+=	lib/pkgconfig/libimsg.pc
BUILDLINK_FILES.imsg-compat+=	lib${LIBABISUFFIX}/pkgconfig/libimsg.pc
.  endif

.endif  # CHECK_BUILTIN.imsg-compat
