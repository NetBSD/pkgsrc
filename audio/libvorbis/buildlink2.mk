# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/06 06:54:33 jlam Exp $
#
# This Makefile fragment is included by packages that use libvorbis.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libvorbis to the dependency pattern
#     for the version of libvorbis desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(LIBVORBIS_BUILDLINK2_MK)
LIBVORBIS_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.libvorbis?=	libvorbis>=1.0.0.7
DEPENDS+=	${BUILDLINK_DEPENDS.libvorbis}:../../audio/libvorbis

EVAL_PREFIX+=	BUILDLINK_PREFIX.libvorbis=libvorbis
BUILDLINK_PREFIX.libvorbis_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libvorbis=	include/vorbis/*
BUILDLINK_FILES.libvorbis+=	lib/libvorbis.*
BUILDLINK_FILES.libvorbis+=	lib/libvorbisenc.*
BUILDLINK_FILES.libvorbis+=	lib/libvorbisfile.*

.include "../../audio/libogg/buildlink2.mk"

BUILDLINK_TARGETS+=	libvorbis-buildlink

libvorbis-buildlink: _BUILDLINK_USE

.endif	# LIBVORBIS_BUILDLINK2_MK
