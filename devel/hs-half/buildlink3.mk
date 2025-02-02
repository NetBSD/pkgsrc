# $NetBSD: buildlink3.mk,v 1.8 2025/02/02 13:05:08 pho Exp $

BUILDLINK_TREE+=	hs-half

.if !defined(HS_HALF_BUILDLINK3_MK)
HS_HALF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-half+=	hs-half>=0.3.2
BUILDLINK_ABI_DEPENDS.hs-half+=	hs-half>=0.3.2nb1
BUILDLINK_PKGSRCDIR.hs-half?=	../../devel/hs-half
.endif	# HS_HALF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-half
