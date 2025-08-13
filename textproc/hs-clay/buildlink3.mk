# $NetBSD: buildlink3.mk,v 1.6 2025/08/13 11:07:29 pho Exp $

BUILDLINK_TREE+=	hs-clay

.if !defined(HS_CLAY_BUILDLINK3_MK)
HS_CLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-clay+=	hs-clay>=0.15.0
BUILDLINK_ABI_DEPENDS.hs-clay+=	hs-clay>=0.15.0nb4
BUILDLINK_PKGSRCDIR.hs-clay?=	../../textproc/hs-clay
.endif	# HS_CLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-clay
