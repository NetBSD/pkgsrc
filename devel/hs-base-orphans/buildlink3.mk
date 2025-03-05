# $NetBSD: buildlink3.mk,v 1.15 2025/03/05 03:39:03 pho Exp $

BUILDLINK_TREE+=	hs-base-orphans

.if !defined(HS_BASE_ORPHANS_BUILDLINK3_MK)
HS_BASE_ORPHANS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base-orphans+=	hs-base-orphans>=0.9.3
BUILDLINK_ABI_DEPENDS.hs-base-orphans+=	hs-base-orphans>=0.9.3nb2
BUILDLINK_PKGSRCDIR.hs-base-orphans?=	../../devel/hs-base-orphans
.endif	# HS_BASE_ORPHANS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base-orphans
