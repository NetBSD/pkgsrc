# $NetBSD: buildlink2.mk,v 1.3 2003/02/20 16:02:35 salo Exp $

.if !defined(MUSICBRAINZ_BUILDLINK2_MK)
MUSICBRAINZ_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			musicbrainz
BUILDLINK_DEPENDS.musicbrainz?=		musicbrainz>=2.0.0
BUILDLINK_PKGSRCDIR.musicbrainz?=	../../audio/musicbrainz

EVAL_PREFIX+=			BUILDLINK_PREFIX.musicbrainz=musicbrainz
BUILDLINK_PREFIX.musicbrainz_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.musicbrainz=	include/musicbrainz/*
BUILDLINK_FILES.musicbrainz+=	include/musicbrainz/*/*
BUILDLINK_FILES.musicbrainz+=	lib/libmusicbrainz.*

BUILDLINK_TARGETS+=	musicbrainz-buildlink

musicbrainz-buildlink: _BUILDLINK_USE

.endif	# MUSICBRAINZ_BUILDLINK2_MK
