# $NetBSD: buildlink.mk,v 1.4 2001/07/27 13:33:33 jlam Exp $
#
# This Makefile fragment is included by packages that use socks5.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.socks5 to the dependency pattern
#     for the version of socks5 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(SOCKS5_BUILDLINK_MK)
SOCKS5_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.socks5?=	socks5>=1.0.2
DEPENDS+=	${BUILDLINK_DEPENDS.socks5}:../../net/socks5

EVAL_PREFIX+=			BUILDLINK_PREFIX.socks5=socks5
BUILDLINK_PREFIX.socks5_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.socks5=		include/socks.h
BUILDLINK_FILES.socks5+=	lib/libsocks5.a
BUILDLINK_FILES.socks5+=	lib/libsocks5_sh.*

BUILDLINK_TARGETS.socks5=	socks5-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.socks5}

pre-configure: ${BUILDLINK_TARGETS.socks5}
socks5-buildlink: _BUILDLINK_USE

.endif	# SOCKS5_BUILDLINK_MK
