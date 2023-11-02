# $NetBSD: buildlink3.mk,v 1.5 2023/11/02 06:36:33 pho Exp $

BUILDLINK_TREE+=	hs-half

.if !defined(HS_HALF_BUILDLINK3_MK)
HS_HALF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-half+=	hs-half>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-half+=	hs-half>=0.3.1nb4
BUILDLINK_PKGSRCDIR.hs-half?=	../../devel/hs-half
.endif	# HS_HALF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-half
