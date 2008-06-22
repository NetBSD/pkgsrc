# $NetBSD: buildlink3.mk,v 1.8 2008/06/22 01:21:31 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EET_BUILDLINK3_MK:=	${EET_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	eet
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Neet}
BUILDLINK_PACKAGES+=	eet
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}eet

.if ${EET_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.eet+=	eet>=1.0.1
BUILDLINK_PKGSRCDIR.eet?=	../../devel/eet
.endif	# EET_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
