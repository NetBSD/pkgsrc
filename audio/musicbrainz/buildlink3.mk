# $NetBSD: buildlink3.mk,v 1.13 2006/07/08 23:10:37 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MUSICBRAINZ_BUILDLINK3_MK:=	${MUSICBRAINZ_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	musicbrainz
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmusicbrainz}
BUILDLINK_PACKAGES+=	musicbrainz
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}musicbrainz

.if !empty(MUSICBRAINZ_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.musicbrainz+=		musicbrainz>=2.0.2
BUILDLINK_ABI_DEPENDS.musicbrainz+=	musicbrainz>=2.1.2nb2
BUILDLINK_PKGSRCDIR.musicbrainz?=	../../audio/musicbrainz
.endif	# MUSICBRAINZ_BUILDLINK3_MK

.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
