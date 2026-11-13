# $NetBSD: buildlink3.mk,v 1.13 2026/11/13 14:38:46 pho Exp $

BUILDLINK_TREE+=	hs-Only

.if !defined(HS_ONLY_BUILDLINK3_MK)
HS_ONLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Only+=	hs-Only>=0.1
BUILDLINK_ABI_DEPENDS.hs-Only+=	hs-Only>=0.1nb13
BUILDLINK_PKGSRCDIR.hs-Only?=	../../devel/hs-Only
.endif	# HS_ONLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Only
