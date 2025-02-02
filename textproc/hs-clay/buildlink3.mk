# $NetBSD: buildlink3.mk,v 1.4 2025/02/02 13:05:51 pho Exp $

BUILDLINK_TREE+=	hs-clay

.if !defined(HS_CLAY_BUILDLINK3_MK)
HS_CLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-clay+=	hs-clay>=0.15.0
BUILDLINK_ABI_DEPENDS.hs-clay+=	hs-clay>=0.15.0nb2
BUILDLINK_PKGSRCDIR.hs-clay?=	../../textproc/hs-clay
.endif	# HS_CLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-clay
