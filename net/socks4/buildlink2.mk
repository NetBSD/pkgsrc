# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/06 06:54:46 jlam Exp $
#
# This Makefile fragment is included by packages that use socks4.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.socks4 to the dependency pattern
#     for the version of socks4 desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(SOCKS4_BUILDLINK2_MK)
SOCKS4_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.socks4?=	socks4>=2.2
DEPENDS+=	${BUILDLINK_DEPENDS.socks4}:../../net/socks4

EVAL_PREFIX+=	BUILDLINK_PREFIX.socks4=socks4
BUILDLINK_PREFIX.socks4_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.socks4=		lib/libsocks4.*
BUILDLINK_TRANSFORM+=		l:socks:socks4

BUILDLINK_TARGETS+=		socks4-buildlink

socks4-buildlink: _BUILDLINK_USE

.endif	# SOCKS4_BUILDLINK2_MK
