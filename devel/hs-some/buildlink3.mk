# $NetBSD: buildlink3.mk,v 1.3 2023/01/24 18:34:14 pho Exp $

BUILDLINK_TREE+=	hs-some

.if !defined(HS_SOME_BUILDLINK3_MK)
HS_SOME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-some+=	hs-some>=1.0.4
BUILDLINK_ABI_DEPENDS.hs-some+=	hs-some>=1.0.4.1
BUILDLINK_PKGSRCDIR.hs-some?=	../../devel/hs-some
.endif	# HS_SOME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-some
