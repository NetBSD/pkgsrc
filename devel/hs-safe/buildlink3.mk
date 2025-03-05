# $NetBSD: buildlink3.mk,v 1.15 2025/03/05 03:39:26 pho Exp $

BUILDLINK_TREE+=	hs-safe

.if !defined(HS_SAFE_BUILDLINK3_MK)
HS_SAFE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-safe+=	hs-safe>=0.3.21
BUILDLINK_ABI_DEPENDS.hs-safe+=	hs-safe>=0.3.21nb3
BUILDLINK_PKGSRCDIR.hs-safe?=	../../devel/hs-safe
.endif	# HS_SAFE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-safe
