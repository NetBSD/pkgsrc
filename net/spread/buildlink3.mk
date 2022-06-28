# $NetBSD: buildlink3.mk,v 1.10 2022/06/28 11:35:20 wiz Exp $

BUILDLINK_TREE+=	spread

.if !defined(SPREAD_BUILDLINK3_MK)
SPREAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spread+=	spread>=3.17.1
BUILDLINK_ABI_DEPENDS.spread?=	spread>=3.17.3nb13
BUILDLINK_PKGSRCDIR.spread?=	../../net/spread
BUILDLINK_INCDIRS.spread?=	include/spread
.endif # SPREAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-spread
