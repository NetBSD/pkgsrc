# $NetBSD: buildlink.mk,v 1.1 2001/06/28 20:23:29 jlam Exp $
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

BUILDLINK_DEPENDS.socks4?=	socks4-*
DEPENDS+=	${BUILDLINK_DEPENDS.socks4}:../../net/socks4

BUILDLINK_PREFIX.socks4=	${LOCALBASE}
BUILDLINK_FILES.socks4+=	lib/libsocks4.*

BUILDLINK_TARGETS.socks4=	socks4-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.socks4}

pre-configure: ${BUILDLINK_TARGETS.socks4}
socks4-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# SOCKS4_BUILDLINK_MK
