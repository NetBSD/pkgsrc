# $NetBSD: buildlink2.mk,v 1.4 2003/03/18 12:11:56 tron Exp $

.if !defined(NETPBM_BUILDLINK2_MK)
NETPBM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		netpbm
BUILDLINK_DEPENDS.netpbm?=	netpbm>=9.24
BUILDLINK_PKGSRCDIR.netpbm?=	../../graphics/netpbm

EVAL_PREFIX+=	BUILDLINK_PREFIX.netpbm=netpbm
BUILDLINK_PREFIX.netpbm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.netpbm=		include/bitio.h
BUILDLINK_FILES.netpbm+=	include/colorname.h
BUILDLINK_FILES.netpbm+=	include/nstring.h
BUILDLINK_FILES.netpbm+=	include/pam.h
BUILDLINK_FILES.netpbm+=	include/pammap.h
BUILDLINK_FILES.netpbm+=	include/pbm.h
BUILDLINK_FILES.netpbm+=	include/pbmfont.h
BUILDLINK_FILES.netpbm+=	include/pgm.h
BUILDLINK_FILES.netpbm+=	include/pm.h
BUILDLINK_FILES.netpbm+=	include/pm_config.h
BUILDLINK_FILES.netpbm+=	include/pnm.h
BUILDLINK_FILES.netpbm+=	include/ppm.h
BUILDLINK_FILES.netpbm+=	include/ppmcmap.h
BUILDLINK_FILES.netpbm+=	include/ppmfloyd.h
BUILDLINK_FILES.netpbm+=	include/shhopt.h
BUILDLINK_FILES.netpbm+=	lib/libnetpbm.*

.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

BUILDLINK_TARGETS+=	netpbm-buildlink netpbm-buildlink-lib

netpbm-buildlink: _BUILDLINK_USE

netpbm-buildlink-lib:
	${_PKG_SILENT}${_PKG_DEBUG}				\
	cd ${BUILDLINK_DIR}/lib;				\
	for _NETPBM_LIB in pbm pgm pnm ppm; do			\
	  ${LN} -fs libnetpbm.a lib$${_NETPBM_LIB}.a;		\
	  ${LN} -fs libnetpbm.so.*.* lib$${_NETPBM_LIB}.so;	\
	done
	
.endif	# NETPBM_BUILDLINK2_MK
