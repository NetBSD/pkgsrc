# $NetBSD: buildlink3.mk,v 1.6 2022/01/18 02:48:12 pho Exp $

BUILDLINK_TREE+=	hs-safe

.if !defined(HS_SAFE_BUILDLINK3_MK)
HS_SAFE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-safe+=	hs-safe>=0.3.19
BUILDLINK_ABI_DEPENDS.hs-safe+=	hs-safe>=0.3.19nb2
BUILDLINK_PKGSRCDIR.hs-safe?=	../../devel/hs-safe
.endif	# HS_SAFE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-safe
