# $NetBSD: buildlink.mk,v 1.1 2002/05/03 20:52:59 jtb Exp $
#
# This Makefile fragment is included by packages that use hdf5.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.hdf5 to the dependency pattern
#     for the version of hdf5 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(HDF5_BUILDLINK_MK)
HDF5_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.hdf5?=	hdf5>=1.4.3
BUILD_DEPENDS+=			${BUILDLINK_DEPENDS.hdf5}:../../devel/hdf5

EVAL_PREFIX+=			BUILDLINK_PREFIX.hdf5=hdf5
BUILDLINK_PREFIX.hdf5_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.hdf5=	include/H5ACpublic.h
BUILDLINK_FILES.hdf5+=	include/H5Apublic.h
BUILDLINK_FILES.hdf5+=	include/H5Bpublic.h
BUILDLINK_FILES.hdf5+=	include/H5Dpublic.h
BUILDLINK_FILES.hdf5+=	include/H5Epublic.h
BUILDLINK_FILES.hdf5+=	include/H5FDcore.h
BUILDLINK_FILES.hdf5+=	include/H5FDfamily.h
BUILDLINK_FILES.hdf5+=	include/H5FDgass.h
BUILDLINK_FILES.hdf5+=	include/H5FDlog.h
BUILDLINK_FILES.hdf5+=	include/H5FDmpio.h
BUILDLINK_FILES.hdf5+=	include/H5FDmulti.h
BUILDLINK_FILES.hdf5+=	include/H5FDpublic.h
BUILDLINK_FILES.hdf5+=	include/H5FDsec2.h
BUILDLINK_FILES.hdf5+=	include/H5FDsrb.h
BUILDLINK_FILES.hdf5+=	include/H5FDstdio.h
BUILDLINK_FILES.hdf5+=	include/H5FDstream.h
BUILDLINK_FILES.hdf5+=	include/H5Fpublic.h
BUILDLINK_FILES.hdf5+=	include/H5Gpublic.h
BUILDLINK_FILES.hdf5+=	include/H5HGpublic.h
BUILDLINK_FILES.hdf5+=	include/H5HLpublic.h
BUILDLINK_FILES.hdf5+=	include/H5Ipublic.h
BUILDLINK_FILES.hdf5+=	include/H5MMpublic.h
BUILDLINK_FILES.hdf5+=	include/H5Opublic.h
BUILDLINK_FILES.hdf5+=	include/H5Ppublic.h
BUILDLINK_FILES.hdf5+=	include/H5Rpublic.h
BUILDLINK_FILES.hdf5+=	include/H5Spublic.h
BUILDLINK_FILES.hdf5+=	include/H5Tpublic.h
BUILDLINK_FILES.hdf5+=	include/H5Zpublic.h
BUILDLINK_FILES.hdf5+=	include/H5api_adpt.h
BUILDLINK_FILES.hdf5+=	include/H5pubconf.h
BUILDLINK_FILES.hdf5+=	include/H5public.h
BUILDLINK_FILES.hdf5+=	lib/libhdf5.*

BUILDLINK_TARGETS.hdf5=	hdf5-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.hdf5}

pre-configure: ${BUILDLINK_TARGETS.hdf5}
hdf5-buildlink: _BUILDLINK_USE

.endif	# HDF5_BUILDLINK_MK
