# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/06 06:54:41 jlam Exp $
#
# This Makefile fragment is included by packages that use netpbm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.netpbm to the dependency pattern
#     for the version of netpbm desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(NETPBM_BUILDLINK2_MK)
NETPBM_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.netpbm?=	netpbm>=9.24
DEPENDS+=	${BUILDLINK_DEPENDS.netpbm}:../../graphics/netpbm

EVAL_PREFIX+=	BUILDLINK_PREFIX.netpbm=netpbm
BUILDLINK_PREFIX.netpbm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.netpbm=		include/bitio.h
BUILDLINK_FILES.netpbm+=	include/pam.h
BUILDLINK_FILES.netpbm+=	include/pammap.h
BUILDLINK_FILES.netpbm+=	include/pbm.h
BUILDLINK_FILES.netpbm+=	include/pgm.h
BUILDLINK_FILES.netpbm+=	include/pm.h
BUILDLINK_FILES.netpbm+=	include/pm_config.h
BUILDLINK_FILES.netpbm+=	include/pnm.h
BUILDLINK_FILES.netpbm+=	include/ppm.h
BUILDLINK_FILES.netpbm+=	include/ppmcmap.h
BUILDLINK_FILES.netpbm+=	include/ppmfloyd.h
BUILDLINK_FILES.netpbm+=	include/shhopt.h
BUILDLINK_FILES.netpbm+=	lib/libpbm.*
BUILDLINK_FILES.netpbm+=	lib/libpgm.*
BUILDLINK_FILES.netpbm+=	lib/libpnm.*
BUILDLINK_FILES.netpbm+=	lib/libppm.*

BUILDLINK_TARGETSS=	netpbm-buildlink

netpbm-buildlink: _BUILDLINK_USE

.endif	# NETPBM_BUILDLINK2_MK
