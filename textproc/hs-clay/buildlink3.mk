# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:40 pho Exp $

BUILDLINK_TREE+=	hs-clay

.if !defined(HS_CLAY_BUILDLINK3_MK)
HS_CLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-clay+=	hs-clay>=0.15.0
BUILDLINK_ABI_DEPENDS.hs-clay+=	hs-clay>=0.15.0nb1
BUILDLINK_PKGSRCDIR.hs-clay?=	../../textproc/hs-clay
.endif	# HS_CLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-clay
