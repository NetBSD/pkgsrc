# $NetBSD: buildlink3.mk,v 1.13 2025/03/05 03:39:28 pho Exp $

BUILDLINK_TREE+=	hs-setlocale

.if !defined(HS_SETLOCALE_BUILDLINK3_MK)
HS_SETLOCALE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-setlocale+=	hs-setlocale>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-setlocale+=	hs-setlocale>=1.0.0.10nb10
BUILDLINK_PKGSRCDIR.hs-setlocale?=	../../devel/hs-setlocale
.endif	# HS_SETLOCALE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-setlocale
