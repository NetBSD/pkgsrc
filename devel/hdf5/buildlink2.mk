# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:12 jlam Exp $

.if !defined(HDF5_BUILDLINK2_MK)
HDF5_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		hdf5
BUILDLINK_DEPENDS.hdf5?=	hdf5>=1.4.3
BUILDLINK_PKGSRCDIR.hdf5?=	../../devel/hdf5

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

BUILDLINK_TARGETS+=	hdf5-buildlink

hdf5-buildlink: _BUILDLINK_USE

.endif	# HDF5_BUILDLINK2_MK
