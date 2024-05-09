# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:31:47 pho Exp $

BUILDLINK_TREE+=	hs-binary-orphans

.if !defined(HS_BINARY_ORPHANS_BUILDLINK3_MK)
HS_BINARY_ORPHANS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-binary-orphans+=	hs-binary-orphans>=1.0.4
BUILDLINK_ABI_DEPENDS.hs-binary-orphans+=	hs-binary-orphans>=1.0.4.1nb2
BUILDLINK_PKGSRCDIR.hs-binary-orphans?=		../../devel/hs-binary-orphans
.endif	# HS_BINARY_ORPHANS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-binary-orphans
