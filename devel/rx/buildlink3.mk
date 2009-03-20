# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:29 joerg Exp $

BUILDLINK_TREE+=	rx

.if !defined(RX_BUILDLINK3_MK)
RX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rx+=		rx>=1.5
BUILDLINK_PKGSRCDIR.rx?=	../../devel/rx
.endif # RX_BUILDLINK3_MK

BUILDLINK_TREE+=	-rx
