# $NetBSD: buildlink.mk,v 1.1.1.1 2002/08/23 11:39:28 dillo Exp $
#
# This Makefile fragment is included by packages that use libsndfile.
#
# This file was created automatically using createbuildlink 1.5.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libsndfile to the dependency pattern
#     for the version of libsndfile desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBSNDFILE_BUILDLINK_MK)
LIBSNDFILE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libsndfile?=		libsndfile>=1.0.0
DEPENDS+=	${BUILDLINK_DEPENDS.libsndfile}:../../audio/libsndfile

EVAL_PREFIX+=	BUILDLINK_PREFIX.libsndfile=libsndfile
BUILDLINK_PREFIX.libsndfile_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libsndfile+=	include/sndfile.h
BUILDLINK_FILES.libsndfile+=	lib/libsndfile.*
BUILDLINK_FILES.libsndfile+=	lib/pkgconfig/sndfile.pc

.include "../../devel/pkgconfig/buildlink.mk"

BUILDLINK_TARGETS.libsndfile=	libsndfile-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libsndfile}
BUILDLINK_TARGETS+=		${BUILDLINK_PKG_CONFIG}

pre-configure: ${BUILDLINK_TARGETS}
libsndfile-buildlink: _BUILDLINK_USE

.endif	# LIBSNDFILE_BUILDLINK_MK
