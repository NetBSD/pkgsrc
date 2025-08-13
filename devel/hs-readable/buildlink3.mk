# $NetBSD: buildlink3.mk,v 1.2 2025/08/13 11:06:54 pho Exp $

BUILDLINK_TREE+=	hs-readable

.if !defined(HS_READABLE_BUILDLINK3_MK)
HS_READABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-readable+=	hs-readable>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-readable+=	hs-readable>=0.3.1nb1
BUILDLINK_PKGSRCDIR.hs-readable?=	../../devel/hs-readable

.endif	# HS_READABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-readable
