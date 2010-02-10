# $NetBSD: resolv.buildlink3.mk,v 1.4 2010/02/10 17:28:57 joerg Exp $
#
# This Makefile fragment is included by package Makefiles and
# buildlink3.mk files for the packages that need a thread-safe
# DNS resolver.
#
# It defines the variables RESOLV_LDFLAGS and RESOLV_LIBS,
# which are also exported into the CONFIGURE_ENV and MAKE_ENV environments.
#
# Package-settable variables:
#
# RESOLV_AUTO_VARS
#	When set to "yes", the necessary flags are added automatically
#	to LDFLAGS and friends.
#
#	Default: no
#
# Keywords: resolv
#

RESOLV_BUILDLINK3_MK:=	${RESOLV_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

RESOLV_AUTO_VARS?=	no
CHECK_BUILTIN.resolv=	no

.if ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
USE_BUILTIN.resolv?=	yes

BUILDLINK_LDFLAGS.resolv=	# empty, in libc
.elif (${OPSYS} == "NetBSD" && empty(OS_VERSION:M[012].*)) || \
    (${OPSYS} == "Darwin" && empty(OS_VERSION:M[0123467].*))
USE_BUILTIN.resolv?=	yes

# BIND 9 resolver
BUILDLINK_LDFLAGS.resolv=	-lresolv
.else
USE_BUILTIN.resolv?=	no
.endif

.if !empty(USE_BUILTIN.resolv:M[yY][eE][sS])
BUILDLINK_TREE+=		resolv -resolv
BUILDLINK_AUTO_VARS.resolv=	${RESOLV_AUTO_VARS}
.else
.  include "../../net/bind95/buildlink3.mk"

BUILDLINK_AUTO_VARS.bind=	${RESOLV_AUTO_VARS}
BUILDLINK_LDFLAGS.resolv=	${BUILDLINK_LDFLAGS.bind}
BUILDLINK_LIBS.resolv=		${BUILDLINK_LIBS.bind}
.endif

.if !empty(RESOLV_BUILDLINK3_MK:M+)
#
# Define user-visible RESOLV_{LDFLAGS,LIBS} as compiler options used
# to link code that needs a thread-safe DNS resolver.
#
RESOLV_LDFLAGS=	${BUILDLINK_LDFLAGS.resolv}
RESOLV_LIBS=	${BUILDLINK_LIBS.resolv}
CONFIGURE_ENV+=	RESOLV_LDFLAGS=${RESOLV_LDFLAGS:Q}
CONFIGURE_ENV+=	RESOLV_LIBS=${RESOLV_LIBS:Q}
MAKE_ENV+=	RESOLV_LDFLAGS=${RESOLV_LDFLAGS:Q}
MAKE_ENV+=	RESOLV_LIBS=${RESOLV_LIBS:Q}
.endif	# RESOLV_BUILDLINK3_MK
