# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:16 jlam Exp $

.if !defined(NETCDF_BUILDLINK2_MK)
NETCDF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		netcdf
BUILDLINK_DEPENDS.netcdf?=	netcdf>=3.4
BUILDLINK_PKGSRCDIR.netcdf?=	../../devel/netcdf

EVAL_PREFIX+=				BUILDLINK_PREFIX.netcdf=netcdf
BUILDLINK_PREFIX.netcdf_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.netcdf=			include/netcdf.h
BUILDLINK_FILES.netcdf+=		include/netcdf.inc
BUILDLINK_FILES.netcdf+=		include/netcdf.hh
BUILDLINK_FILES.netcdf+=		include/ncvalues.hh
BUILDLINK_FILES.netcdf+=		lib/libnetcdf.*
BUILDLINK_FILES.netcdf+=		lib/libnetcdf_c++.*

BUILDLINK_TARGETS+=	netcdf-buildlink

netcdf-buildlink: _BUILDLINK_USE

.endif	# NETCDF_BUILDLINK2_MK
