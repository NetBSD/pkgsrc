# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/21 23:00:33 jlam Exp $

.if !defined(NETPBM_BUILDLINK2_MK)
NETPBM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		netpbm
BUILDLINK_DEPENDS.netpbm?=	netpbm>=9.24
BUILDLINK_PKGSRCDIR.netpbm?=	../../graphics/netpbm

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
