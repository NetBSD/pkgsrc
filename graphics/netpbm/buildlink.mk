# $NetBSD: buildlink.mk,v 1.5 2001/07/27 13:33:31 jlam Exp $
#
# This Makefile fragment is included by packages that use netpbm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.netpbm to the dependency pattern
#     for the version of netpbm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(NETPBM_BUILDLINK_MK)
NETPBM_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.netpbm?=	netpbm>=9.7
DEPENDS+=	${BUILDLINK_DEPENDS.netpbm}:../../graphics/netpbm

EVAL_PREFIX+=			BUILDLINK_PREFIX.netpbm=netpbm
BUILDLINK_PREFIX.netpbm_DEFAULT=	${LOCALBASE}
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

.endif	# NETPBM_BUILDLINK_MK
