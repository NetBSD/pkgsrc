# $NetBSD: buildlink.mk,v 1.4 2001/07/01 22:59:27 jlam Exp $
#
# This Makefile fragment is included by packages that use socks4.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.socks4 to the dependency pattern
#     for the version of socks4 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(SOCKS4_BUILDLINK_MK)
SOCKS4_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.socks4?=	socks4>=2.2
DEPENDS+=	${BUILDLINK_DEPENDS.socks4}:../../net/socks4

BUILDLINK_PREFIX.socks4=	${LOCALBASE}
BUILDLINK_FILES.socks4=		lib/libsocks4.*

BUILDLINK_TARGETS.socks4=	socks4-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.socks4}

pre-configure: ${BUILDLINK_TARGETS.socks4}
socks4-buildlink: _BUILDLINK_USE

.endif	# SOCKS4_BUILDLINK_MK
