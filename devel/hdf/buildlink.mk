# $NetBSD: buildlink.mk,v 1.1 2002/05/03 23:14:52 jtb Exp $
#
# This Makefile fragment is included by packages that use hdf.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.hdf to the dependency pattern
#     for the version of hdf desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(HDF_BUILDLINK_MK)
HDF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.hdf?=		hdf>=4.1r5
BUILD_DEPENDS+=			${BUILDLINK_DEPENDS.hdf}:../../devel/hdf

EVAL_PREFIX+=			BUILDLINK_PREFIX.hdf=hdf
BUILDLINK_PREFIX.hdf_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.hdf=	include/hdf/atom.h
BUILDLINK_FILES.hdf+=	include/hdf/bitvect.h
BUILDLINK_FILES.hdf+=	include/hdf/cdeflate.h
BUILDLINK_FILES.hdf+=	include/hdf/cnbit.h
BUILDLINK_FILES.hdf+=	include/hdf/cnone.h
BUILDLINK_FILES.hdf+=	include/hdf/crle.h
BUILDLINK_FILES.hdf+=	include/hdf/cskphuff.h
BUILDLINK_FILES.hdf+=	include/hdf/df.h
BUILDLINK_FILES.hdf+=	include/hdf/dfan.h
BUILDLINK_FILES.hdf+=	include/hdf/dfconvrt.h
BUILDLINK_FILES.hdf+=	include/hdf/dffunc.inc
BUILDLINK_FILES.hdf+=	include/hdf/dfgr.h
BUILDLINK_FILES.hdf+=	include/hdf/dfi.h
BUILDLINK_FILES.hdf+=	include/hdf/dfivms.h
BUILDLINK_FILES.hdf+=	include/hdf/dfrig.h
BUILDLINK_FILES.hdf+=	include/hdf/dfsd.h
BUILDLINK_FILES.hdf+=	include/hdf/dfstubs.h
BUILDLINK_FILES.hdf+=	include/hdf/dfufp2i.h
BUILDLINK_FILES.hdf+=	include/hdf/dir_mac.h
BUILDLINK_FILES.hdf+=	include/hdf/dynarray.h
BUILDLINK_FILES.hdf+=	include/hdf/glist.h
BUILDLINK_FILES.hdf+=	include/hdf/hbitio.h
BUILDLINK_FILES.hdf+=	include/hdf/hchunks.h
BUILDLINK_FILES.hdf+=	include/hdf/hcomp.h
BUILDLINK_FILES.hdf+=	include/hdf/hcompi.h
BUILDLINK_FILES.hdf+=	include/hdf/hconv.h
BUILDLINK_FILES.hdf+=	include/hdf/hdf.h
BUILDLINK_FILES.hdf+=	include/hdf/hdf.inc
BUILDLINK_FILES.hdf+=	include/hdf/hdf2netcdf.h
BUILDLINK_FILES.hdf+=	include/hdf/hdfi.h
BUILDLINK_FILES.hdf+=	include/hdf/herr.h
BUILDLINK_FILES.hdf+=	include/hdf/hfile.h
BUILDLINK_FILES.hdf+=	include/hdf/hkit.h
BUILDLINK_FILES.hdf+=	include/hdf/hlimits.h
BUILDLINK_FILES.hdf+=	include/hdf/hntdefs.h
BUILDLINK_FILES.hdf+=	include/hdf/hproto.h
BUILDLINK_FILES.hdf+=	include/hdf/hqueue.h
BUILDLINK_FILES.hdf+=	include/hdf/htags.h
BUILDLINK_FILES.hdf+=	include/hdf/linklist.h
BUILDLINK_FILES.hdf+=	include/hdf/local_nc.h
BUILDLINK_FILES.hdf+=	include/hdf/maldebug.h
BUILDLINK_FILES.hdf+=	include/hdf/mcache.h
BUILDLINK_FILES.hdf+=	include/hdf/mfan.h
BUILDLINK_FILES.hdf+=	include/hdf/mfhdf.h
BUILDLINK_FILES.hdf+=	include/hdf/mfgr.h
BUILDLINK_FILES.hdf+=	include/hdf/mstdio.h
BUILDLINK_FILES.hdf+=	include/hdf/netcdf.h
BUILDLINK_FILES.hdf+=	include/hdf/netcdf.inc
BUILDLINK_FILES.hdf+=	include/hdf/patchlevel.h
BUILDLINK_FILES.hdf+=	include/hdf/src.inc
BUILDLINK_FILES.hdf+=	include/hdf/sys_dir_mac.h
BUILDLINK_FILES.hdf+=	include/hdf/tbbt.h
BUILDLINK_FILES.hdf+=	include/hdf/trace.h
BUILDLINK_FILES.hdf+=	include/hdf/vattr.h
BUILDLINK_FILES.hdf+=	include/hdf/vg.h
BUILDLINK_FILES.hdf+=	include/hdf/vgint.h
BUILDLINK_FILES.hdf+=	lib/libdf.*
BUILDLINK_FILES.hdf+=	lib/libmfhdf.*

BUILDLINK_TARGETS.hdf=	hdf-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.hdf}

pre-configure: ${BUILDLINK_TARGETS.hdf}
hdf-buildlink: _BUILDLINK_USE

.endif	# HDF_BUILDLINK_MK
