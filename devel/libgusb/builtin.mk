# $NetBSD: builtin.mk,v 1.1 2026/04/25 13:08:55 vins Exp $

BUILTIN_PKG:=			libgusb
PKGCONFIG_BASE.libgusb=		/usr
PKGCONFIG_FILE.libgusb=		${PKGCONFIG_BASE.libgusb}/lib/pkgconfig/libgusb.pc
PKGCONFIG_FILE.libgusb+=	${PKGCONFIG_BASE.libgusb}/lib${LIBABISUFFIX}/pkgconfig/libgusb.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

CHECK_BUILTIN.libgusb?=	no
.if ${CHECK_BUILTIN.libgusb:tl} == no

.  if ${USE_BUILTIN.libgusb:tl} == yes
BUILDLINK_PREFIX.libgusb=	/usr
BUILDLINK_FILES.libgusb+=	lib/pkgconfig/libgusb.pc
BUILDLINK_FILES.libgusb+=	lib${LIBABISUFFIX}/pkgconfig/libgusb.pc
.  endif

.endif  # CHECK_BUILTIN.libgusb
