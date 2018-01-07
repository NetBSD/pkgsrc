# $NetBSD: buildlink3.mk,v 1.14 2018/01/07 13:04:25 rillig Exp $

BUILDLINK_TREE+=	xvidcore

.if !defined(XVIDCORE_BUILDLINK3_MK)
XVIDCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xvidcore+=	xvidcore>=1.0.0
BUILDLINK_ABI_DEPENDS.xvidcore+=	xvidcore>=1.1.0nb1
BUILDLINK_PKGSRCDIR.xvidcore?=		../../multimedia/xvidcore
.endif # XVIDCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-xvidcore
