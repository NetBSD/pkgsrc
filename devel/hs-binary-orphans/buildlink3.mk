# $NetBSD: buildlink3.mk,v 1.4 2025/01/30 05:09:15 pho Exp $

BUILDLINK_TREE+=	hs-binary-orphans

.if !defined(HS_BINARY_ORPHANS_BUILDLINK3_MK)
HS_BINARY_ORPHANS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-binary-orphans+=	hs-binary-orphans>=1.0.5
BUILDLINK_ABI_DEPENDS.hs-binary-orphans+=	hs-binary-orphans>=1.0.5
BUILDLINK_PKGSRCDIR.hs-binary-orphans?=		../../devel/hs-binary-orphans
.endif	# HS_BINARY_ORPHANS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-binary-orphans
