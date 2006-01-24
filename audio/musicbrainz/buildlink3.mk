# $NetBSD: buildlink3.mk,v 1.8 2006/01/24 07:31:55 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MUSICBRAINZ_BUILDLINK3_MK:=	${MUSICBRAINZ_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	musicbrainz
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmusicbrainz}
BUILDLINK_PACKAGES+=	musicbrainz

.if !empty(MUSICBRAINZ_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.musicbrainz+=		musicbrainz>=2.0.2
BUILDLINK_RECOMMENDED.musicbrainz+=	musicbrainz>=2.1.2nb1
BUILDLINK_PKGSRCDIR.musicbrainz?=	../../audio/musicbrainz
.endif	# MUSICBRAINZ_BUILDLINK3_MK

.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
