# $NetBSD: buildlink2.mk,v 1.4 2004/02/09 00:07:36 chris Exp $

.if !defined(MUSICBRAINZ_BUILDLINK2_MK)
MUSICBRAINZ_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			musicbrainz
BUILDLINK_DEPENDS.musicbrainz?=		musicbrainz>=2.0.2
BUILDLINK_PKGSRCDIR.musicbrainz?=	../../audio/musicbrainz

EVAL_PREFIX+=			BUILDLINK_PREFIX.musicbrainz=musicbrainz
BUILDLINK_PREFIX.musicbrainz_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.musicbrainz=	include/musicbrainz/*.h
BUILDLINK_FILES.musicbrainz+=	include/musicbrainz/*/*.h
BUILDLINK_FILES.musicbrainz+=	lib/libmusicbrainz.*

.include "../../textproc/expat/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	musicbrainz-buildlink

musicbrainz-buildlink: _BUILDLINK_USE

.endif	# MUSICBRAINZ_BUILDLINK2_MK
