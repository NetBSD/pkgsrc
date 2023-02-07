# $NetBSD: buildlink3.mk,v 1.3 2023/02/07 01:40:36 pho Exp $

BUILDLINK_TREE+=	hs-half

.if !defined(HS_HALF_BUILDLINK3_MK)
HS_HALF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-half+=	hs-half>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-half+=	hs-half>=0.3.1nb2
BUILDLINK_PKGSRCDIR.hs-half?=	../../devel/hs-half
.endif	# HS_HALF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-half
