# $NetBSD: builtin.mk,v 1.1 2017/06/08 13:30:16 jlam Exp $

BUILTIN_PKG:=		atf
PKGCONFIG_BASE.atf=	/usr
PKGCONFIG_FILE.atf=	${PKGCONFIG_BASE.atf}/lib/pkgconfig/atf-sh.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

CHECK_BUILTIN.atf?=	no
.if !empty(CHECK_BUILTIN.atf:M[nN][oO])
.  if !empty(USE_BUILTIN.atf:M[yY][eE][sS])
BUILDLINK_PREFIX.atf=	${PKGCONFIG_BASE.atf}
BUILDLINK_FILES.atf+=	lib/pkgconfig/atf-c++.pc
BUILDLINK_FILES.atf+=	lib/pkgconfig/atf-c.pc
BUILDLINK_FILES.atf+=	lib/pkgconfig/atf-sh.pc
.  endif
.endif	# CHECK_BUILTIN.atf
