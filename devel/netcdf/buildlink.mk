# $NetBSD: buildlink.mk,v 1.1 2001/07/29 04:48:03 jlam Exp $
#
# This Makefile fragment is included by packages that use netcdf.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.netcdf to the dependency pattern
#     for the version of netcdf desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(NETCDF_BUILDLINK_MK)
NETCDF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.netcdf?=	netcdf>=3.4
DEPENDS+=	${BUILDLINK_DEPENDS.netcdf}:../../devel/netcdf

EVAL_PREFIX+=				BUILDLINK_PREFIX.netcdf=netcdf
BUILDLINK_PREFIX.netcdf_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.netcdf=			include/netcdf.h
BUILDLINK_FILES.netcdf+=		include/netcdf.inc
BUILDLINK_FILES.netcdf+=		include/netcdf.hh
BUILDLINK_FILES.netcdf+=		include/ncvalues.hh
BUILDLINK_FILES.netcdf+=		lib/libnetcdf.*
BUILDLINK_FILES.netcdf+=		lib/libnetcdf_c++.*

BUILDLINK_TARGETS.netcdf=	netcdf-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.netcdf}

pre-configure: ${BUILDLINK_TARGETS.netcdf}
netcdf-buildlink: _BUILDLINK_USE

.endif	# NETCDF_BUILDLINK_MK
