# $NetBSD: buildlink3.mk,v 1.3 2004/10/15 11:31:48 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EET_BUILDLINK3_MK:=	${EET_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	eet
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Neet}
BUILDLINK_PACKAGES+=	eet

.if !empty(EET_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.eet+=	eet>=0.9.9
BUILDLINK_PKGSRCDIR.eet?=	../../devel/eet
.endif	# EET_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
