# $NetBSD: buildlink3.mk,v 1.1 2023/10/26 02:31:31 pho Exp $

BUILDLINK_TREE+=	hs-byteable

.if !defined(HS_BYTEABLE_BUILDLINK3_MK)
HS_BYTEABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-byteable+=	hs-byteable>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-byteable+=	hs-byteable>=0.1.1
BUILDLINK_PKGSRCDIR.hs-byteable?=	../../devel/hs-byteable
.endif	# HS_BYTEABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-byteable
