# $NetBSD: buildlink3.mk,v 1.12 2025/08/13 11:07:23 pho Exp $

BUILDLINK_TREE+=	hs-byteorder

.if !defined(HS_BYTEORDER_BUILDLINK3_MK)
HS_BYTEORDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-byteorder+=	hs-byteorder>=1.0.4
BUILDLINK_ABI_DEPENDS.hs-byteorder+=	hs-byteorder>=1.0.4nb11
BUILDLINK_PKGSRCDIR.hs-byteorder?=	../../sysutils/hs-byteorder
.endif	# HS_BYTEORDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-byteorder
