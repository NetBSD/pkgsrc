# $NetBSD: buildlink3.mk,v 1.3 2008/01/18 05:06:20 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMUSICBRAINZ_BUILDLINK3_MK:=	${LIBMUSICBRAINZ_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libmusicbrainz
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmusicbrainz}
BUILDLINK_PACKAGES+=	libmusicbrainz
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libmusicbrainz

.if ${LIBMUSICBRAINZ_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libmusicbrainz+=	libmusicbrainz>=3.0.0
BUILDLINK_ABI_DEPENDS.libmusicbrainz?=	libmusicbrainz>=3.0.0nb1
BUILDLINK_PKGSRCDIR.libmusicbrainz?=	../../audio/libmusicbrainz
.endif	# LIBMUSICBRAINZ_BUILDLINK3_MK

.include "../../www/neon/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
