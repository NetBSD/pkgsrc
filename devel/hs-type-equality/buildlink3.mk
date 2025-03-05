# $NetBSD: buildlink3.mk,v 1.9 2025/03/05 03:39:33 pho Exp $

BUILDLINK_TREE+=	hs-type-equality

.if !defined(HS_TYPE_EQUALITY_BUILDLINK3_MK)
HS_TYPE_EQUALITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-type-equality+=	hs-type-equality>=1.0.1
BUILDLINK_ABI_DEPENDS.hs-type-equality+=	hs-type-equality>=1.0.1nb2
BUILDLINK_PKGSRCDIR.hs-type-equality?=		../../devel/hs-type-equality
.endif	# HS_TYPE_EQUALITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-type-equality
