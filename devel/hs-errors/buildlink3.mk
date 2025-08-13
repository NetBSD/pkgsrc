# $NetBSD: buildlink3.mk,v 1.14 2025/08/13 11:06:38 pho Exp $

BUILDLINK_TREE+=	hs-errors

.if !defined(HS_ERRORS_BUILDLINK3_MK)
HS_ERRORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-errors+=	hs-errors>=2.3.0
BUILDLINK_ABI_DEPENDS.hs-errors+=	hs-errors>=2.3.0nb11
BUILDLINK_PKGSRCDIR.hs-errors?=		../../devel/hs-errors

.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.endif	# HS_ERRORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-errors
