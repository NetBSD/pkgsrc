# $NetBSD: buildlink.mk,v 1.2 2002/08/01 05:48:10 jlam Exp $
#
# This Makefile fragment is included by packages that use libmpeg3.
#
# This file was created automatically using createbuildlink 1.5.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libmpeg3 to the dependency pattern
#     for the version of libmpeg3 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBMPEG3_BUILDLINK_MK)
LIBMPEG3_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libmpeg3?=		libmpeg3>=1.3nb2
DEPENDS+=	${BUILDLINK_DEPENDS.libmpeg3}:../../devel/libmpeg3

EVAL_PREFIX+=	BUILDLINK_PREFIX.libmpeg3=libmpeg3
BUILDLINK_PREFIX.libmpeg3_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/libmpeg3.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/bitstream.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/mpeg3atrack.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/mpeg3css.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/mpeg3demux.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/mpeg3io.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/mpeg3private.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/mpeg3private.inc
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/mpeg3title.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/mpeg3vtrack.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/timecode.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/audio/ac3.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/audio/mpeg3audio.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/video/idct.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/video/mpeg3video.h
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/video/slice.h
BUILDLINK_FILES.libmpeg3+=	lib/libmpeg3.*

PTHREAD_OPTS+=	require

.include "../../mk/pthread.buildlink.mk"

BUILDLINK_TARGETS.libmpeg3=	libmpeg3-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libmpeg3}

pre-configure: ${BUILDLINK_TARGETS}
libmpeg3-buildlink: _BUILDLINK_USE

.endif	# LIBMPEG3_BUILDLINK_MK
