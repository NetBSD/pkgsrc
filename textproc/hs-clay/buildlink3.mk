# $NetBSD: buildlink3.mk,v 1.7 2026/11/13 14:39:49 pho Exp $

BUILDLINK_TREE+=	hs-clay

.if !defined(HS_CLAY_BUILDLINK3_MK)
HS_CLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-clay+=	hs-clay>=0.15.0
BUILDLINK_ABI_DEPENDS.hs-clay+=	hs-clay>=0.15.0nb5
BUILDLINK_PKGSRCDIR.hs-clay?=	../../textproc/hs-clay
.endif	# HS_CLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-clay
