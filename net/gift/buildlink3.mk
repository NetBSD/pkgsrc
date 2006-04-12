# $NetBSD: buildlink3.mk,v 1.5 2006/04/12 10:27:29 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GIFT_BUILDLINK3_MK:=	${GIFT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gift
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngift}
BUILDLINK_PACKAGES+=	gift

.if !empty(GIFT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gift+=	gift>=0.11.6
BUILDLINK_ABI_DEPENDS.gift+=	gift>=0.11.6nb2
BUILDLINK_PKGSRCDIR.gift?=	../../net/gift
.endif	# GIFT_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
