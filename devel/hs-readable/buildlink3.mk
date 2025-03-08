# $NetBSD: buildlink3.mk,v 1.1 2025/03/08 02:54:48 pho Exp $

BUILDLINK_TREE+=	hs-readable

.if !defined(HS_READABLE_BUILDLINK3_MK)
HS_READABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-readable+=	hs-readable>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-readable+=	hs-readable>=0.3.1
BUILDLINK_PKGSRCDIR.hs-readable?=	../../devel/hs-readable

.endif	# HS_READABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-readable
