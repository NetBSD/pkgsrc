# $NetBSD: buildlink2.mk,v 1.4 2004/04/12 23:15:01 salo Exp $

.if !defined(LIBVORBIS_BUILDLINK2_MK)
LIBVORBIS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libvorbis
BUILDLINK_DEPENDS.libvorbis?=	libvorbis>=1.0.1
BUILDLINK_PKGSRCDIR.libvorbis?=	../../audio/libvorbis

EVAL_PREFIX+=	BUILDLINK_PREFIX.libvorbis=libvorbis
BUILDLINK_PREFIX.libvorbis_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libvorbis=	include/vorbis/*
BUILDLINK_FILES.libvorbis+=	lib/libvorbis.*
BUILDLINK_FILES.libvorbis+=	lib/libvorbisenc.*
BUILDLINK_FILES.libvorbis+=	lib/libvorbisfile.*

.include "../../multimedia/libogg/buildlink2.mk"

BUILDLINK_TARGETS+=	libvorbis-buildlink

libvorbis-buildlink: _BUILDLINK_USE

.endif	# LIBVORBIS_BUILDLINK2_MK
