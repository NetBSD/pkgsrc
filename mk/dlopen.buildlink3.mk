# $NetBSD: dlopen.buildlink3.mk,v 1.14 2007/04/27 15:02:37 tron Exp $
#
# This Makefile fragment is included by package Makefiles and
# buildlink3.mk files for the packages that use dlopen().
#
DLOPEN_BUILDLINK3_MK:=	${DLOPEN_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(DLOPEN_BUILDLINK3_MK:M+)
CHECK_BUILTIN.dl:=	yes
.include "../../mk/dlopen.builtin.mk"
CHECK_BUILTIN.dl:=	no
.endif	# DLOPEN_BUILDLINK3_MK

DL_AUTO_VARS?=	no

.if !empty(USE_BUILTIN.dl:M[yY][eE][sS])
BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Ndl}
BUILDLINK_PACKAGES+=		dl
BUILDLINK_ORDER:=		${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}dl
BUILDLINK_BUILTIN_MK.dl=	../../mk/dlopen.builtin.mk
BUILDLINK_AUTO_VARS.dl=		${DL_AUTO_VARS}
.elif !empty(MACHINE_PLATFORM:MDarwin-[56].*)
.  include "../../devel/dlcompat/buildlink3.mk"
BUILDLINK_AUTO_VARS.dlcompat=	${DL_AUTO_VARS}
BUILDLINK_LDFLAGS.dl:=		${BUILDLINK_LDFLAGS.dlcompat}
.else
PKG_FAIL_REASON=	"${PKGNAME} requires a working dlopen()."
.endif

.if !empty(DLOPEN_BUILDLINK3_MK:M+)
#
# Define user-visible DL_{CFLAGS,LDFLAGS,LIBS} as compiler options used
# to compile/link code that uses dl*() functions.
#
DL_CFLAGS=	${BUILDLINK_CFLAGS.dl}
DL_LDFLAGS=	${BUILDLINK_LDFLAGS.dl}
DL_LIBS=	${BUILDLINK_LIBS.dl}
CONFIGURE_ENV+=	DL_CFLAGS=${DL_CFLAGS:Q}
CONFIGURE_ENV+=	DL_LDFLAGS=${DL_LDFLAGS:Q}
CONFIGURE_ENV+=	DL_LIBS=${DL_LIBS:Q}
MAKE_ENV+=	DL_CFLAGS=${DL_CFLAGS:Q}
MAKE_ENV+=	DL_LDFLAGS=${DL_LDFLAGS:Q}
MAKE_ENV+=	DL_LIBS=${DL_LIBS:Q}
.endif	# DLOPEN_BUILDLINK3_MK
