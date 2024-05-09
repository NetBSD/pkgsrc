# $NetBSD: buildlink3.mk,v 1.12 2024/05/09 01:31:46 pho Exp $

BUILDLINK_TREE+=	hs-base-orphans

.if !defined(HS_BASE_ORPHANS_BUILDLINK3_MK)
HS_BASE_ORPHANS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base-orphans+=	hs-base-orphans>=0.9.1
BUILDLINK_ABI_DEPENDS.hs-base-orphans+=	hs-base-orphans>=0.9.1nb2
BUILDLINK_PKGSRCDIR.hs-base-orphans?=	../../devel/hs-base-orphans
.endif	# HS_BASE_ORPHANS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base-orphans
