# $NetBSD: buildlink3.mk,v 1.7 2022/02/12 08:50:37 pho Exp $

BUILDLINK_TREE+=	hs-safe

.if !defined(HS_SAFE_BUILDLINK3_MK)
HS_SAFE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-safe+=	hs-safe>=0.3.19
BUILDLINK_ABI_DEPENDS.hs-safe+=	hs-safe>=0.3.19nb3
BUILDLINK_PKGSRCDIR.hs-safe?=	../../devel/hs-safe
.endif	# HS_SAFE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-safe
