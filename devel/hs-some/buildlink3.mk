# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:07 pho Exp $

BUILDLINK_TREE+=	hs-some

.if !defined(HS_SOME_BUILDLINK3_MK)
HS_SOME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-some+=	hs-some>=1.0.3
BUILDLINK_ABI_DEPENDS.hs-some+=	hs-some>=1.0.3nb1
BUILDLINK_PKGSRCDIR.hs-some?=	../../devel/hs-some
.endif	# HS_SOME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-some
