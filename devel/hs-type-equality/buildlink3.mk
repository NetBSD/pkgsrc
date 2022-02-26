# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:10 pho Exp $

BUILDLINK_TREE+=	hs-type-equality

.if !defined(HS_TYPE_EQUALITY_BUILDLINK3_MK)
HS_TYPE_EQUALITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-type-equality+=	hs-type-equality>=1
BUILDLINK_ABI_DEPENDS.hs-type-equality+=	hs-type-equality>=1nb1
BUILDLINK_PKGSRCDIR.hs-type-equality?=		../../devel/hs-type-equality
.endif	# HS_TYPE_EQUALITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-type-equality
