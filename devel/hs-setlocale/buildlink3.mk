# $NetBSD: buildlink3.mk,v 1.11 2024/05/09 01:32:11 pho Exp $

BUILDLINK_TREE+=	hs-setlocale

.if !defined(HS_SETLOCALE_BUILDLINK3_MK)
HS_SETLOCALE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-setlocale+=	hs-setlocale>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-setlocale+=	hs-setlocale>=1.0.0.10nb8
BUILDLINK_PKGSRCDIR.hs-setlocale?=	../../devel/hs-setlocale
.endif	# HS_SETLOCALE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-setlocale
