# $NetBSD: buildlink.mk,v 1.8 2002/01/02 12:39:36 lukem Exp $
#
# This Makefile fragment is included by packages that use libvorbis.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libvorbis to the dependency pattern
#     for the version of libvorbis desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBVORBIS_BUILDLINK_MK)
LIBVORBIS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libvorbis?=	libvorbis>=1.0.0.7
DEPENDS+=	${BUILDLINK_DEPENDS.libvorbis}:../../audio/libvorbis

EVAL_PREFIX+=			BUILDLINK_PREFIX.libvorbis=libvorbis
BUILDLINK_PREFIX.libvorbis_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libvorbis=	include/vorbis/*
BUILDLINK_FILES.libvorbis+=	lib/libvorbis.*
BUILDLINK_FILES.libvorbis+=	lib/libvorbisenc.*
BUILDLINK_FILES.libvorbis+=	lib/libvorbisfile.*

.include "../../audio/libogg/buildlink.mk"

BUILDLINK_TARGETS.libvorbis=	libvorbis-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.libvorbis}

pre-configure: ${BUILDLINK_TARGETS.libvorbis}
libvorbis-buildlink: _BUILDLINK_USE

.endif	# LIBVORBIS_BUILDLINK_MK
