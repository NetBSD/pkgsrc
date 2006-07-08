# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 22:39:08 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EET_BUILDLINK3_MK:=	${EET_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	eet
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Neet}
BUILDLINK_PACKAGES+=	eet
BUILDLINK_ORDER+=	eet

.if !empty(EET_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.eet+=	eet>=0.9.9
BUILDLINK_PKGSRCDIR.eet?=	../../devel/eet
.endif	# EET_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
