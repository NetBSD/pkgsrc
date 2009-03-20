# $NetBSD: dlopen.buildlink3.mk,v 1.17 2009/03/20 19:25:01 joerg Exp $
#
# This Makefile fragment is included by package Makefiles and
# buildlink3.mk files for the packages that use dlopen().
#
# It defines the variables DL_CFLAGS, DL_LDFLAGS and DL_LIBS, which
# are also exported into the CONFIGURE_ENV and MAKE_ENV environments.
#
# Package-settable variables:
#
# DL_AUTO_VARS
#	When set to "yes", the necessary flags are added automatically
#	to CFLAGS and friends.
#
#	Default: no
#
# Keywords: dl dlopen
#

DLOPEN_BUILDLINK3_MK:=	${DLOPEN_BUILDLINK3_MK}+

.include "bsd.fast.prefs.mk"

.if !empty(DLOPEN_BUILDLINK3_MK:M+)
CHECK_BUILTIN.dl:=	yes
.include "dlopen.builtin.mk"
CHECK_BUILTIN.dl:=	no
.endif	# DLOPEN_BUILDLINK3_MK

DL_AUTO_VARS?=	no

.if !empty(USE_BUILTIN.dl:M[yY][eE][sS])
BUILDLINK_TREE+=		dl -dl
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
