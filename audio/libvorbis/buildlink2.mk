# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/08/22 21:04:17 jlam Exp $

.if !defined(LIBVORBIS_BUILDLINK2_MK)
LIBVORBIS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libvorbis
BUILDLINK_DEPENDS.libvorbis?=	libvorbis>=1.0.0.8
BUILDLINK_PKGSRCDIR.libvorbis?=	../../audio/libvorbis

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
