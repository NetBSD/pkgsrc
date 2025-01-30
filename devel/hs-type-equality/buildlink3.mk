# $NetBSD: buildlink3.mk,v 1.7 2025/01/30 14:43:35 pho Exp $

BUILDLINK_TREE+=	hs-type-equality

.if !defined(HS_TYPE_EQUALITY_BUILDLINK3_MK)
HS_TYPE_EQUALITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-type-equality+=	hs-type-equality>=1.0.1
BUILDLINK_ABI_DEPENDS.hs-type-equality+=	hs-type-equality>=1.0.1
BUILDLINK_PKGSRCDIR.hs-type-equality?=		../../devel/hs-type-equality
.endif	# HS_TYPE_EQUALITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-type-equality
