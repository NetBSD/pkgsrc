# $NetBSD: buildlink.mk,v 1.1 2001/06/16 19:23:19 jlam Exp $
#
# This Makefile fragment is included by packages that use netpbm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define NETPBM_REQD to the version of netpbm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(NETPBM_BUILDLINK_MK)
NETPBM_BUILDLINK_MK=	# defined

NETPBM_REQD?=		9.7
DEPENDS+=		netpbm>=${NETPBM_REQD}:../../graphics/netpbm

BUILDLINK_PREFIX.netpbm=	${LOCALBASE}
BUILDLINK_FILES.netpbm=		include/pbm.h
BUILDLINK_FILES.netpbm+=	include/pbmplus.h
BUILDLINK_FILES.netpbm+=	include/pgm.h
BUILDLINK_FILES.netpbm+=	include/pnm.h
BUILDLINK_FILES.netpbm+=	include/ppm.h
BUILDLINK_FILES.netpbm+=	include/ppmcmap.h
BUILDLINK_FILES.netpbm+=	include/shhopt.h
BUILDLINK_FILES.netpbm+=	lib/libpbm.*
BUILDLINK_FILES.netpbm+=	lib/libpgm.*
BUILDLINK_FILES.netpbm+=	lib/libpnm.*
BUILDLINK_FILES.netpbm+=	lib/libppm.*

BUILDLINK_TARGETS.netpbm=	netpbm-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.netpbm}

pre-configure: ${BUILDLINK_TARGETS.netpbm}
netpbm-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# NETPBM_BUILDLINK_MK
