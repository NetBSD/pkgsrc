# $NetBSD: buildlink3.mk,v 1.5 2004/03/05 19:25:08 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MUSICBRAINZ_BUILDLINK3_MK:=	${MUSICBRAINZ_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	musicbrainz
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmusicbrainz}
BUILDLINK_PACKAGES+=	musicbrainz

.if !empty(MUSICBRAINZ_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.musicbrainz+=		musicbrainz>=2.0.2
BUILDLINK_PKGSRCDIR.musicbrainz?=	../../audio/musicbrainz

.include "../../textproc/expat/buildlink3.mk"

.endif	# MUSICBRAINZ_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
