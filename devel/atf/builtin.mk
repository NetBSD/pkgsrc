# $NetBSD: builtin.mk,v 1.2 2025/03/30 07:51:54 wiz Exp $

BUILTIN_PKG:=		atf
PKGCONFIG_BASE.atf=	/usr
PKGCONFIG_FILE.atf=	${PKGCONFIG_BASE.atf}/lib/pkgconfig/atf-sh.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

CHECK_BUILTIN.atf?=	no
.if ${CHECK_BUILTIN.atf:tl} == no
.  if ${USE_BUILTIN.atf:tl} == yes
BUILDLINK_PREFIX.atf=	${PKGCONFIG_BASE.atf}
BUILDLINK_FILES.atf+=	lib/pkgconfig/atf-c++.pc
BUILDLINK_FILES.atf+=	lib/pkgconfig/atf-c.pc
BUILDLINK_FILES.atf+=	lib/pkgconfig/atf-sh.pc
.  endif
.endif	# CHECK_BUILTIN.atf
